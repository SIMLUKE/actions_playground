/*
** EPITECH PROJECT, 2024
** lib arrays
** File description:
** uncomment of strings
*/

#include "arrays.h"
#include <stdlib.h>

static int my_strlen_nocomment(const char *str, const char *comment_c)
{
    int tot = 0;
    _Bool on_comment = 0;

    for (int i = 0; str[i]; i++) {
        if (ischar_in_str(str[i], comment_c))
            on_comment = 1;
        if (on_comment == 1)
            tot += 1;
    }
    return tot;
}

char *my_struncomment(char *str, char const *comment_c)
{
    char *new_str = NULL;

    if (str == NULL || occurences(str, "#") == 0)
        return str;
    new_str = malloc(sizeof(char) * my_strlen_nocomment(str, comment_c));
    for (int i = 0; str[i] && ischar_in_str(str[i], comment_c); i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
