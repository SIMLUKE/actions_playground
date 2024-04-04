/*
** EPITECH PROJECT, 2024
** array lib
** File description:
** any char ** destroyers
*/

#include <stdlib.h>

void free_starstar(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i] != NULL)
            free(tab[i]);
    if (tab != NULL)
        free(tab);
}
