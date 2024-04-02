/*
** EPITECH PROJECT, 2024
** my strlen
** File description:
** lib
*/

#include <stddef.h>

int my_strlen(const char *str)
{
    int tot = 0;

    if (str == NULL)
        return 0;
    while (*str) {
        tot++;
        str++;
    }
    return tot;
}
