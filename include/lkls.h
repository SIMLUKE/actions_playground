/*
** EPITECH PROJECT, 2024
** linked lists
** File description:
** header for linked list
*/

#ifndef LKLS_H
    #define LKLS_H

    #include <stddef.h>

typedef struct node_s {
    char *name;
    char *values;
    struct node_s *next;
} node_t;

int free_list(node_t **current);
int delete_link(node_t **current, char *name);
int insert(node_t **head, char *name, char *values);
int insert_front(node_t **head, char *name, char *values);
int count_nodes(node_t **head);
int search(node_t **head);
int sort(node_t **head);
int print_list(node_t **current);

#endif
