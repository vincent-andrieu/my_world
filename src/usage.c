/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** my_radar usage
*/

#include "my.h"

int usage(int exit_value, char *binary_name)
{
    my_putstr("3D World simulation\n\nUSAGE\n\t");
    my_putstr(binary_name);
    my_putstr("\n\nOPTIONS\n\t-h\tprint the usage and quit.\n");
    return exit_value;
}