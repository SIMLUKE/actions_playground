/*
** EPITECH PROJECT, 2023
** my radar
** File description:
** handling of given filename
*/

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "mini_print.h"

static int read_file(char **arr, FILE *fd, int n_of_lines)
{
    size_t size = 0;
    ssize_t char_gotten = 0;
    int lines = 0;

    if (fd == NULL) {
        mini_printf(2, "file not found\n");
        return 1;
    }
    for (lines = 0; char_gotten != -1 && lines != n_of_lines; lines++) {
        arr[lines] = NULL;
        char_gotten = getline(&(arr[lines]), &size, fd);
        if (char_gotten == -1 && lines == 0)
            return 1;
        if (arr[lines] == NULL)
            return 1;
    }
    fclose(fd);
    arr[lines - 1] = NULL;
    return 0;
}

int get_nlines(const char *filename)
{
    int lines = 0;
    char *temp = NULL;
    size_t size = 0;
    ssize_t char_gotten = 0;
    FILE *fd = fopen(filename, "r");

    if (fd == NULL) {
        mini_printf(2, "file not found\n");
        return -1;
    }
    for (lines = 0; char_gotten != -1; lines++) {
        temp = NULL;
        char_gotten = getline(&temp, &size, fd);
        if (char_gotten == -1 && lines == 0)
            return -1;
        free(temp);
    }
    fclose(fd);
    return lines;
}

char **open_file(const char *filename)
{
    char **arr = NULL;
    int n_of_lines = get_nlines(filename);

    if (n_of_lines == -1)
        return NULL;
    arr = malloc(sizeof(char *) * (n_of_lines + 1));
    if (arr == NULL)
        return NULL;
    if (read_file(arr, fopen(filename, "r"), n_of_lines))
        return NULL;
    return arr;
}
