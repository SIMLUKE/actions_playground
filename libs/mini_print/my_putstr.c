/*
** EPITECH PROJECT, 2024
** my putstr
** File description:
** lib
*/

#include <unistd.h>
#include "mini_print.h"

static int my_strlen(const char *str)
{
    int tot = 0;

    if (str == NULL)
        return -1;
    while (*str) {
        tot++;
        str++;
    }
    return tot;
}

int my_putstr(const char *str, int output)
{
    int tot = my_strlen(str);

    if (tot == -1)
        return -1;
    write(output, str, tot);
    return tot;
}
