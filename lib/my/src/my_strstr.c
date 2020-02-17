/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** find a substring in a string
*/

#include <stdlib.h>

static char *compare_strs(char *str, char const *to_find, int i)
{
    for (int k = 0; str[i + k] == to_find[k]; k++) {
        if (to_find[k + 1] == '\0')
            return str += i;
        if (str[i + k + 1] == '\0')
            return 0;
    }
    return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    if (to_find[0] == '\0')
        return str;
    for (int i = 0; str[i] != '\0'; i++)
        if (compare_strs(str, to_find, i) != 0)
            return compare_strs(str, to_find, i);
    return NULL;
}
