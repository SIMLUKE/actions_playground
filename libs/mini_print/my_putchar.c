/*
** EPITECH PROJECT, 2024
** my putchar
** File description:
** lib
*/

#include <unistd.h>

int my_putchar(char c, int output)
{
    write(output, &c, 1);
    return 1;
}
