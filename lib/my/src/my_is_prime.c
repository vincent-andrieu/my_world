/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** return a bool if the param number is prime
*/

int my_is_prime(int nb)
{
    if (nb < 0)
        nb = -nb;
    if ((nb % 2 == 0 && nb != 2) || nb == 0 || nb == 1)
        return 0;
    if (nb == 2)
        return 1;
    for (int i = 3; i * i <= nb; i += 2)
        if (nb % i == 0)
            return 0;
    return 1;
}
