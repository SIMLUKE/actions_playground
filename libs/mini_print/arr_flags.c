/*
** EPITECH PROJECT, 2024
** mini prinf
** File description:
** fucntions for printing arrays
*/

#include "mini.h"
#include "mini_print.h"
#include <stdarg.h>

int flagtab(va_list arg, int output)
{
    char **tab = va_arg(arg, char **);
    int counter = 0;

    while (*tab != NULL) {
        counter += my_putstr(*tab, output);
        counter += my_putchar('\n', output);
        tab++;
    }
    return counter;
}

int flagunknown(char c, int output)
{
    my_putchar('%', output);
    my_putchar(c, output);
    return 2;
}
