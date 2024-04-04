/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my strcomp
*/

#include "arrays.h"

int my_strcmp(const char *tocomp, const char *src)
{
    if (my_strlen(tocomp) != my_strlen(src))
        return 1;
    for (int i = 0; tocomp[i]; i++)
        if (tocomp[i] != src[i])
            return 1;
    return 0;
}
