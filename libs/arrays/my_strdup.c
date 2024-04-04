/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** creates a memory zone for an array of strings
*/

#include "arrays.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    char *copie;
    int maxstr = my_strlen(str);

    if (str == NULL)
        return NULL;
    copie = malloc(sizeof(char) * (maxstr) + 1);
    if (copie == NULL)
        return NULL;
    for (int i = 0; i < maxstr; i++) {
        copie[i] = str[i];
    }
    copie[maxstr] = '\0';
    return copie;
}
