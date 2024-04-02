/*
** EPITECH PROJECT, 2024
** linked list
** File description:
** insert function
*/

#include <stdlib.h>
#include "lkls.h"
#include "arrays.h"

static int fill_node(node_t *node, char *name, char *values)
{
    node->name = my_strdup(name);
    node->values = my_strdup(values);
    return 0;
}

int insert(node_t **head, char *name, char *values)
{
    node_t *new_node;

    if (head == NULL)
        return 84;
    new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return 84;
    fill_node(new_node, name, values);
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int insert_front(node_t **head, char *name, char *values)
{
    node_t *new_node;

    if (head == NULL)
        return 84;
    if (*head == NULL || (*head)->next == NULL) {
        new_node = malloc(sizeof(node_t));
        new_node->next = NULL;
        fill_node(new_node, name, values);
        if (*head == NULL)
            *head = new_node;
        else
            (*head)->next = new_node;
        return 0;
    }
    return insert_front(&(*head)->next, name, values);
}
