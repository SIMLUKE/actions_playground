/*
** EPITECH PROJECT, 2024
** array lib
** File description:
** any char ** creator
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"

static int find_first_quote(const char *str, char const *separators)
{
    uint tot = 0;
    _Bool on_char = 0;
    _Bool next_is_sep = 0;

    if (str == NULL)
        return tot;
    for (uint i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\"')
            return tot;
        next_is_sep = (ischar_in_str(str[i + 1],
            separators) || str[i + 1] == '\0');
        if (!ischar_in_str(str[i], NULL))
            on_char = (!ischar_in_str(str[i], NULL) &&
            !ischar_in_str(str[i], separators));
        if (on_char && next_is_sep) {
            tot++;
        }
    }
    return tot;
}

static int get_offset(const char *str, const char *separators)
{
    int off = 0;

    while ((*str == '\"' || ischar_in_str(*str, separators)) && *str) {
        off += 1;
        str++;
    }
    return off;
}

static int apply_offset(const char *str, char *line, char const *separators)
{
    int tot = 0;

    tot += my_strlen(line);
    str += tot;
    tot += get_offset(str, separators);
    return tot;
}

char **my_str_to_quotes(const char *str, const char *separators)
{
    int wordcount = 0;
    char **tab = NULL;
    int quote = 0;
    char *str_cpy = my_strdup(str);

    tab = my_append_tab(tab, strtok(str_cpy, separators));
    str += apply_offset(str, tab[wordcount], separators);
    while (*str && tab[wordcount] != NULL) {
        quote = find_first_quote(str, separators);
        while (tab[wordcount] != NULL && quote != 0 && wordcount != quote) {
            wordcount += 1;
            tab = my_append_tab(tab, strtok(NULL, separators));
            str += apply_offset(str, tab[wordcount], separators);
        }
        wordcount += 1;
        tab = my_append_tab(tab, strtok(NULL, "\""));
        str += apply_offset(str, tab[wordcount], separators);
    }
    free(str_cpy);
    return tab;
}
