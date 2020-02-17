/*
** EPITECH PROJECT, 2019
** my_str_malloc
** File description:
** malloc n char in a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *my_strcpy(char *dest, char const *src);

char *my_str_malloc(char *str, int const size, char const empty)
{
    char *temp = my_strdup(str);
    int len = my_strlen(str) + size + 1;

    free(str);
    str = malloc(sizeof(char) * len);
    my_strcpy(str, temp);
    for (int i = my_strlen(temp); i < len; i++)
        str[i] = empty;
    str[len] = '\0';
    free(temp);
    return str;
}