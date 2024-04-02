/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my get nbr
*/

#include "my.h"

static int findmulti(const char *str)
{
    int multi = 1;

    if (str[0] == '-')
        multi = multi * -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            multi *= 10;
    }
    return multi / 10;
}

int my_getnbr(const char *str)
{
    double res = 0;
    int z = 0;
    int multi = findmulti(str);

    while (str[z]) {
        if (str[z] == '-')
            z++;
        res = res + multi * (str[z] - 48);
        multi = multi / 10;
        z++;
    }
    return res;
}
