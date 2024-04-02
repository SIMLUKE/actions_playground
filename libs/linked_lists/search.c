/*
** EPITECH PROJECT, 2024
** linked list
** File description:
** insert function
*/

#include "lkls.h"

int search(node_t **head)
{
    (void) head;
    return 1;
}

int count_nodes(node_t **head)
{
    if (head == NULL || *head == NULL)
        return 0;
    return count_nodes(&(*head)->next) + 1;
}
