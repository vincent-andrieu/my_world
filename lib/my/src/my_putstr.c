/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int len;

    if (str == NULL)
        return 84;
    len = my_strlen(str);
    write(1, str, len);
    return len;
}