/*
** EPITECH PROJECT, 2023
** my radar
** File description:
** couters of any kind
*/

#include <stdlib.h>
#include "arrays.h"

uint len_arr(void **arr)
{
    int tot = 0;

    if (arr == NULL)
        return tot;
    for (int i = 0; arr[i] != NULL; i++)
        tot++;
    return tot;
}

uint count_to_x(const char *buff, const char *separators, const char *ignore)
{
    int xlen = 0;
    int on_word = 0;

    if (buff == NULL)
        return xlen;
    for (uint i = 0; buff[i] != '\0' &&
        (on_word == 0 || (ischar_in_str(buff[i], separators) == 0)); i++)
        if (!ischar_in_str(buff[i], separators) &&
            !ischar_in_str(buff[i], ignore)) {
            xlen++;
            on_word = 1;
        }
    return xlen;
}

uint count_lines(const char *buff,
    const char *separators, const char *ignore)
{
    uint tot = 0;
    _Bool on_char = 0;
    _Bool next_is_sep = 0;

    if (buff == NULL)
        return tot;
    for (uint i = 0; buff[i] != '\0'; i++) {
        next_is_sep = (ischar_in_str(buff[i + 1],
            separators) || buff[i + 1] == '\0');
        if (!ischar_in_str(buff[i], ignore))
            on_char = (!ischar_in_str(buff[i], ignore) &&
            !ischar_in_str(buff[i], separators));
        if (on_char && next_is_sep) {
            tot++;
        }
    }
    return tot;
}

uint occurences(const char *str, const char *tolookfor)
{
    uint tot = 0;

    for (uint i = 0; str[i]; i++) {
        if (ischar_in_str(str[i], tolookfor))
            tot++;
    }
    return tot;
}
