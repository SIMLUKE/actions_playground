/*
** EPITECH PROJECT, 2024
** main
** File description:
** test
*/

#include "mini_print.h"
#include "arrays.h"
#include "freef.h"

#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

typedef enum status_s {
    NOTFOUND = 1,
    FOUND = 0
} status_t;

typedef struct env_s {
    char **env;
    int last_exit;
} env_t;

typedef enum pipe_fd_s {
    OUT,
    IN
} pipe_fd_t;

// env_handling.c
char **find_var(char *var, char **env);
void unsetenvi(env_t *environement, char **arguments);
void setenvi(env_t *environement, char **arguments);
void cd_custom(env_t *environement, char **arguments);

// binary_execution.c
int binaries(env_t *environement, char **command, char *input);

// status_handling.c
int status_handling(env_t *environement,
    char **command, pid_t pid, int status);

// request_input.c
void request_input(char **input);
int input_handling(env_t *environement, char *input);

// ll_decoder.c
int ll_decoder(env_t *env, char *input);

static char const SPECIAL_CHARS[] = {
    '|',
    '&',
    ';',
    '<',
    '>',
    '\0'
};

typedef struct ll_node_s {
    char *value;
    int fds[2];
    int (*func) (struct ll_node_s *self, env_t *env);
    bool is_operator;
    struct ll_node_s *right;
    struct ll_node_s *left;
} ll_node_t;

// symbols_handling.c
int no_redir(ll_node_t *self, env_t *env);
int pipe_redir(ll_node_t *self, env_t *env);

int input_w_redir(ll_node_t *self, env_t *);
int output_w_redir(ll_node_t *self, env_t *);
int output_a_redir(ll_node_t *self, env_t *);
int input_a_redir(ll_node_t *self, env_t *);

// ll_parser.c
ll_node_t *ll_parser(char *input);
int lauch_command(ll_node_t *self, env_t *env);

typedef struct model_s {
    char *sep;
    int (*exec_func) (struct ll_node_s *self, env_t *env);
} model_t;

static const model_t MODEL_SEP[] = {
    {";", no_redir},
    {"&&", NULL},
    {"||", NULL},
    {"&", NULL},
    {"|", pipe_redir},
    {"<<", input_a_redir},
    {"<", input_w_redir},
    {">>", output_a_redir},
    {">", output_w_redir},
    {NULL, NULL}
};

int abso(int i)
{
    return i < 0 ? i * -1 : i;
}

int pipe_redir(ll_node_t *self, env_t *env)
{
    int fds[2];
    pid_t pid = 0;
    int stdin_save = dup(STDIN_FILENO);

    pipe(fds);
    pid = fork();
    if (pid == 0) {
        dup2(fds[IN], STDOUT_FILENO);
        close(fds[IN]);
        self->right->func(self->right, env);
        exit(0);
    } else {
        dup2(fds[OUT], STDIN_FILENO);
        dup2(stdin_save, fds[IN]);
        close(fds[IN]);
        self->left->func(self->left, env);
    }
    return 0;
}

int no_redir(ll_node_t *, env_t *)
{
    return 0;
}

int input_w_redir(ll_node_t *, env_t *)
{
    return 0;
}

int input_a_redir(ll_node_t *, env_t *)
{
    return 0;
}

int output_w_redir(ll_node_t *, env_t *)
{
    return 0;
}

int output_a_redir(ll_node_t *, env_t *)
{
    return 0;
}

static int offset_to_sep(char const *str,
    char const *separators, char const *first_address)
{
    int offset = 0;

    while (str != first_address && !ischar_in_str(*str, separators)) {
        offset -= 1;
        str--;
    }
    return offset;
}

static int sep_to_offset(char const *str,
    char const *separators, char const *first_address)
{
    int offset = 0;

    while (str != first_address && ischar_in_str(*str, separators)) {
        offset -= 1;
        str--;
    }
    return offset;
}

static char *alloc_str(int offset)
{
    char *str = malloc(sizeof(char) * (offset + 1));

    for (int i = 0; i < offset; i++)
        str[i] = 1;
    str[offset] = '\0';
    return str;
}

static char *format(char const *str, char const *first_address, int offset)
{
    char *new_str = NULL;

    if (first_address == (str + offset))
        offset -= 1;
    offset = abso(offset);
    new_str = alloc_str(offset);
    for (int i = offset - 1; i >= 0; i--){
        new_str[i] = *str;
        str--;
    }
    return new_str;
}

static char *format_sep(char const *str,
    char const *separators, char const *first_address)
{
    char *new_str = NULL;
    int offset = sep_to_offset(str, separators, first_address);

    offset = abso(offset);
    new_str = alloc_str(offset);
    for (int i = offset - 1; i >= 0; i--){
        new_str[i] = *str;
        str--;
    }
    return new_str;
}

static ll_node_t *init_node(char *cmd)
{
    ll_node_t *node = malloc(sizeof(ll_node_t));

    *(node) = (ll_node_t) {0};
    node->value = cmd;
    return node;
}

static bool get_func(ll_node_t *current)
{
    for (int i = 0; MODEL_SEP[i].sep != NULL; i++)
        if (my_strcmp(MODEL_SEP[i].sep, current->value) == 0) {
            current->func = MODEL_SEP[i].exec_func;
            return true;
        }
    return false;
}

static void ll_filler(char *cmd, ll_node_t **head)
{
    ll_node_t *temp = *head;
    ll_node_t *node = init_node(cmd);

    if (*head == NULL){
        *head = node;
        return;
    }
    if (get_func(node)) {
        node->right = temp;
        node->is_operator = true;
        *head = node;
    } else {
        (*head)->func = NULL;
        (*head)->left = node;
    }
}

void print_tree(ll_node_t *current, int depth)
{
    if (current == NULL)
        return;
    print_tree(current->left, depth + 1);
    for (int i = 0; i < depth; i++)
        mini_printf(1, i == depth - 1 ? "|-" : "  ");
    mini_printf(1, "%s\n", current->value);
    print_tree(current->right, depth + 1);
}

ll_node_t *ll_parser(char *input)
{
    ll_node_t *first_node = NULL;
    char const *first_add = input;
    input += my_strlen(input) - 1;
    int offset = 0;

    while (input != first_add) {
        offset = offset_to_sep(input, SPECIAL_CHARS, first_add);
        if (ischar_in_str(*input, SPECIAL_CHARS)) {
            ll_filler(format_sep(input, SPECIAL_CHARS, first_add), &first_node);
            input += sep_to_offset(input, SPECIAL_CHARS, first_add);
        } else {
            ll_filler(format(input, first_add, offset), &first_node);
            input += offset;
        }
    }
    return first_node;
}

int main(int argc, char **argv)
{
    char **commands = my_str_to_arr(argv[1], ";", "\n");
    ll_node_t *root = NULL;

    for (int i = 0; commands[i] != NULL; i++) {
        root = ll_parser(commands[i]);
        print_tree(root, 0);
    }
    return 0;
}
