/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdbool.h>
#include "my.h"

float my_get_float(char *str)
{
    bool toggle = false;
    float nb = (float) my_getnbr(str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '.')
            toggle = true;
        else if (toggle)
            nb /= 10;
    }
    return nb;
}