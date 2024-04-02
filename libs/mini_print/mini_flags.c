/*
** EPITECH PROJECT, 2023
** mini flags
** File description:
** contains the flags for mini_printf
*/

#include "mini.h"
#include "mini_print.h"

int flags(va_list arg, int output)
{
    return my_putstr(va_arg(arg, char *), output);
}

int flagc(va_list arg, int output)
{
    my_putchar((char) va_arg(arg, int), output);
    return 1;
}

int flagid(va_list arg, int output)
{
    int temp = va_arg(arg, int);

    my_put_nbr(temp, output);
    return count_digits(temp);
}

int flagpourcent(va_list arg, int output)
{
    (void) arg;
    my_putchar('%', output);
    return 1;
}
