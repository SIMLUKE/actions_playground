/*
** EPITECH PROJECT, 2023
** mini printf real
** File description:
** the REAL deal
*/

#include "mini.h"
#include "mini_print.h"
#include <stdarg.h>

static int flag_checker(char c, va_list thelist, int output)
{
    int counter = 0;
    int bytesprinted = 0;

    while (flag_arr[counter].c != 0) {
        if (flag_arr[counter].c == c) {
            bytesprinted += flag_arr[counter].func(thelist, output);
        }
        counter++;
    }
    if (bytesprinted == 0) {
        bytesprinted = flagunknown(c, output);
    }
    return bytesprinted;
}

int mini_printf(int output, const char *format, ...)
{
    int bytesprinted = 0;
    va_list thelist;
    int strcounter = 0;

    va_start(thelist, format);
    while (format[strcounter]) {
        if (format[strcounter] == '%') {
            strcounter++;
            bytesprinted += flag_checker(format[strcounter], thelist, output);
        } else {
            my_putchar(format[strcounter], output);
        }
        strcounter++;
    }
    va_end(thelist);
    return bytesprinted;
}
