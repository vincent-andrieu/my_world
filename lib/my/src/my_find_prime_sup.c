/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find sup prime
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        return 2;
    for (int i = nb; i <= 2147483647; i++)
        if (my_is_prime(i))
            return i;
    return 0;
}
