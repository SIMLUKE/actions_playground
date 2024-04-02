/*
** EPITECH PROJECT, 2024
** linked list
** File description:
** delete function
*/

#include "freef.h"
#include "lkls.h"
#include "arrays.h"

static int node_delete(node_t **current)
{
    node_t *tmp;

    freef("%a%a", (*current)->values, (*current)->name);
    tmp = *current;
    *current = (*current)->next;
    freef("%a", tmp);
    return 0;
}

static int node_free(node_t **current)
{
    freef("%a%a%a", (*current)->values, (*current)->name, *current);
    return 0;
}

int delete_link(node_t **current, char *name)
{
    if (current == NULL || *current == NULL)
        return 84;
    if (my_strcmp((*current)->name, name)) {
        node_delete(current);
        return 0;
    }
    return delete_link(&(*current)->next, name);
}

int free_list(node_t **current)
{
    node_t **tmp;

    if (current == NULL || *current == NULL)
        return 84;
    tmp = &(*current)->next;
    free_list(tmp);
    node_free(current);
    return 0;
}
