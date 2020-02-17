/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return the string len
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
