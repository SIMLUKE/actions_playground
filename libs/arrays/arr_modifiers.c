/*
** EPITECH PROJECT, 2023
** array lib
** File description:
** array modifiers
*/

#include <unistd.h>
#include <stdlib.h>
#include "arrays.h"

char **my_append_tab(char **tab, const char *value)
{
    int lines = len_arr((void **) tab) + 1;
    char **new_tab = malloc(sizeof(char *) * (lines + 1));

    if (new_tab == NULL)
        return NULL;
    if (tab != NULL)
        for (int i = 0; tab[i] != NULL; i++) {
            new_tab[i] = tab[i];
        }
    new_tab[lines - 1] = my_strdup(value);
    new_tab[lines] = NULL;
    free(tab);
    return new_tab;
}

char **my_remove_tab(char **tab, const char *value)
{
    int lines = len_arr((void **) tab) - 1;
    int line_counter = 0;
    char **new_tab = malloc(sizeof(char *) * (lines + 1));
    char **line;

    if (new_tab == NULL)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        line = my_str_to_arr(tab[i], "=", NULL);
        if (my_strcmp(line[0], value) == 0) {
            free(tab[i]);
            i += 1;
        }
        new_tab[line_counter] = tab[i];
        line_counter += 1;
        free_starstar(line);
    }
    new_tab[lines] = NULL;
    free(tab);
    return new_tab;
}

char *strdup_clean(char *str, const char *toclean)
{
    int len = my_strlen(str) - occurences(str, toclean);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int new_counter = 0;

    if (new_str == NULL)
        return NULL;
    new_str[len] = '\0';
    for (int i = 0; str[i]; i += 1) {
        if (ischar_in_str(str[i], toclean)) {
            new_str[new_counter] = str[i];
            new_counter += 1;
        }
    }
    free(str);
    return new_str;
}
