/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** manage floats
*/

#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "my_world.h"

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

void put_float(int fd, double nbr)
{
    int ent = (int) nbr;

    my_put_fdnbr(fd, ent);
    write(fd, ".", 1);
    nbr -= ent;
    for (int i = 0; i < 6; i++)
        nbr *= 10;
    my_put_fdnbr(fd, nbr);
}