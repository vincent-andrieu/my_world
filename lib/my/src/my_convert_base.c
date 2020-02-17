/*
** EPITECH PROJECT, 2019
** convert_base
** File description:
** convert from any base to any base
*/

char *my_revstr(char *str);

int my_getnbr(char const *str);

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

static char get_rest(int num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num - 10 + 'A';
}

static char *my_putnbr_base(int nbr, int base, char *result)
{
    int is_neg = nbr < 0;
    int i = 0;

    if (is_neg)
        nbr = -nbr;
    for (i = 0; nbr > 0; i++) {
        result[i] = get_rest(nbr % base);
        nbr /= base;
    }
    if (is_neg) {
        result[i] = '-';
        i++;
    }
    result[i] = '\0';
    my_revstr(result);
    return result;
}

char *my_convert_base(char const *nbr, int base1, int base2)
{
    int nb_len =  my_strlen(nbr);
    int dec = 0;
    int num = my_getnbr(nbr);
    char result[num < 0 ? -num : num];

    for (int i = 0; i < nb_len; i++)
        dec += (nbr[i] - 48) * my_compute_power_rec(base1, nb_len - i - 1);
    return my_putnbr_base(dec, base2, result);
}