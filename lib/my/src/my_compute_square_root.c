/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** return the square root
*/

static int clock_square_root(int nb, int i)
{
    if (i * i == nb)
        return i;
    if (i <= 0)
        return 0;
    return clock_square_root(nb, i - 1);
}

int my_compute_square_root(int nb)
{
    return clock_square_root(nb, nb);
}
