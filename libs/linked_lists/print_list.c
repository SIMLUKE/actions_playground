/*
** EPITECH PROJECT, 2024
** linked lists
** File description:
** display function
*/

#include "lkls.h"
#include "mini_print.h"

// add any display function you would like
static void node_print(node_t *node)
{
    mini_printf(1, "%s=%s\n", node->name, node->values);
    return;
}

int print_list(node_t **current)
{
    if (current == NULL || *current == NULL)
        return 84;
    node_print(*current);
    return print_list(&(*current)->next);
}
