/*
** EPITECH PROJECT, 2019
** my_strndup
** File description:
** allocate memory and copy n string char
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (n + 1));

    if (dest == NULL)
        return NULL;
    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}