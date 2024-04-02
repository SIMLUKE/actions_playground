/*
** EPITECH PROJECT, 2024
** array lib
** File description:
** any char ** creator
*/

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

char **tab_dub(char **tab)
{
    char **new_tab;
    int lines = len_arr((void **) tab);

    new_tab = malloc(sizeof(char *) * (lines + 1));
    if (new_tab == NULL)
        return NULL;
    new_tab[lines] = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        new_tab[i] = my_strdup(tab[i]);
        if (new_tab[i] == NULL)
            return NULL;
    }
    return new_tab;
}

static int fill_word(const char *str, char *word,
    const char *separators, const char *ignore)
{
    int offset = 0;
    int x = 0;
    int len = count_to_x(str, separators, ignore);
    int on_word = 0;

    while ((ischar_in_str(*str, separators) || on_word == 0) || len != x){
        if (!ischar_in_str(*str, separators) && !ischar_in_str(*str, ignore)) {
            word[x] = *str;
            x += 1;
            on_word = 1;
        }
        str++;
        offset++;
    }
    word[len] = '\0';
    return offset;
}

char **my_str_to_arr(const char *str,
    const char *separators, const char *ignore)
{
    int ylen = count_lines(str, separators, ignore);
    int len = 0;
    char **tab = malloc(sizeof(char *) * (size_t) (ylen + 1));

    if (tab == NULL)
        return NULL;
    for (int y = 0; y != ylen; y++) {
        len = count_to_x(str, separators, ignore);
        if (len == 0)
            return NULL;
        tab[y] = malloc(sizeof(char) * (size_t) (len + 1));
        if (tab[y] == NULL)
            return NULL;
        str += fill_word(str, tab[y], separators, ignore);
    }
    tab[ylen] = NULL;
    return tab;
}
