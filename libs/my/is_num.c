/*
** EPITECH PROJECT, 2024
** lib
** File description:
** checks if str is numeric
*/

int is_num(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}
