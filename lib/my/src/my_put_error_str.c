/*
** EPITECH PROJECT, 2019
** my_put_error_str
** File description:
** print a char as error
*/

#include <unistd.h>
#include "my.h"

int my_put_error_str(char const *str)
{
    int len;

    if (str == NULL)
        return 84;
    len = my_strlen(str);
    write(2, str, len);
    return len;
}