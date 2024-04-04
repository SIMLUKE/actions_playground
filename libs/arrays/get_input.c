/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main loops for the game
*/

#include <stdio.h>
#include <stdlib.h>

char *get_input(void)
{
    ssize_t input_size = 0;
    size_t temp = 0;
    char *input = NULL;

    while (input_size == 0) {
        input_size = getline(&input, &temp, stdin);
        if (input_size == -1 && input != NULL)
            free(input);
        if (input_size == -1) {
            return NULL;
        }
    }
    return input;
}
