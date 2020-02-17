/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** print N if parameter < and P if parameter > or null
*/

#include <stdbool.h>

bool my_isneg(int n)
{
    if (n < 0)
        return true;
    return false;
}
