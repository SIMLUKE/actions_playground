/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** just what to include when using the lib
*/

#ifndef PRINT_H
    #define PRINT_H
int my_putchar(char, int output);
int my_putstr(const char *str, int output);
void my_put_nbr(int nb, int output);
int count_digits(int nb);
int mini_printf(int output, const char *, ...);
#endif
