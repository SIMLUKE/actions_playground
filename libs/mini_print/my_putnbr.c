/*
** EPITECH PROJECT, 2024
** my putnbr
** File description:
** lib
*/

#include "mini_print.h"

void my_put_nbr(int nb, int output)
{
    if (nb < 0) {
        my_putchar('-', output);
        nb = nb * - 1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10, output);
    }
    my_putchar(nb % 10 + 48, output);
}

int count_digits(int nb)
{
    int tot = 0;

    if (nb < 0) {
        nb = nb * - 1;
        tot = tot + 1;
    }
    while (nb > 10) {
        nb = nb / 10;
        tot++;
    }
    return tot + 1;
}
