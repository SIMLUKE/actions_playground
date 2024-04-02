/*
** EPITECH PROJECT, 2023
** header for mini printf
** File description:
** stores my structs
*/

#pragma once
#include <stdarg.h>
#include <unistd.h>

int flags(va_list arg, int output);
int flagc(va_list arg, int output);
int flagid(va_list arg, int output);
int flagpourcent(va_list arg, int output);
int flagunknown(char, int output);
int flagtab(va_list arg, int output);

typedef struct flags {
    char c;
    int (*func)(va_list, int);
} flagos_t;

static const flagos_t flag_arr[] = {
    {'c', flagc},
    {'s', flags},
    {'i', flagid},
    {'d', flagid},
    {'t', flagtab},
    {'%', flagpourcent},
    {0, NULL}
};
