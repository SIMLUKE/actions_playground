/*
** EPITECH PROJECT, 2024
** lib
** File description:
** header for lib
*/

#ifndef ARRAYS_H
    #define ARRAYS_H
    #include <stdlib.h>

static const int TO_READ = 10;

// checkers.c
_Bool ischar_in_str(char c, const char *separators);
int str_in_tab(char const *const *tab, char const *str);
_Bool str_contains(const char *str, const char *tocheck);
_Bool find_char_str(char const *str, char const *to_check);

// file_handling.c
char *get_input(void);
char **open_file(const char *filename);

// arr_destructors.c
void free_starstar(char **tab);

//counters.c
uint len_arr(void **arr);
uint count_to_x(const char *buff, const char *separators, const char *ignore);
uint count_lines(const char *buff, const char *separators, const char *ignore);
uint occurences(const char *str, const char *tolookfor);

// str_to_quotes.c
char **my_str_to_quotes(const char *str, const char *separators);

// arr_creators.c
char **my_str_to_arr(const char *str,
    const char *separators, const char *ignore);
char **tab_dub(char **tab);

// arr_modifiers.c
char **my_remove_tab(char **tab, const char *value);
char **my_append_tab(char **tab, const char *value);

// my_strdup.c
char *my_strdup(const char *str);

//my_strcat.c
char *my_strcat(uint n_of_words, ...);

// my_strcomp.c
int my_strcmp(const char *tocomp, const char *src);

// my_strlen.c
int my_strlen(const char *);

// my_struncomment.c
char *my_struncomment(char *str, char const *comment_c);
#endif
