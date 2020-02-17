/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print a number
*/

int my_putchar(char c);

static int get_num_nbr(int nbr)
{
    int n = 1;

    if (nbr < 0)
        nbr = -nbr;
    for (int dix = 10; dix <= nbr; n++) {
        dix *= 10;
        if (n >= 10)
            break;
    }
    return n;
}

static int my_pow(int x, int y)
{
    int result = x;

    for (int i = 1; i < y; i++) {
        result = result * x;
    }
    return result;
}

static int big_num(int nbr)
{
    if (nbr >= 1000000000 && nbr < 2000000000) {
        nbr = 1;
    } else if (nbr >= 2000000000) {
        nbr = 2;
    }
    return nbr;
}

static int get_digit_at_num(int nbr, int at)
{
    int dix = my_pow(10, at);

    if (at < 10) {
        nbr %= dix;
        nbr /= dix / 10;
    } else {
        nbr = big_num(nbr);
    }
    return nbr;
}

int my_put_nbr(int nb)
{
    int num = get_num_nbr(nb);
    int n_char = 0;

    if (nb < 0) {
        n_char += my_putchar('-');
        if (nb < -2147483647) {
            n_char += my_putchar(2 + '0');
            nb = -147483648;
            num = get_num_nbr(nb);
        }
        nb = -nb;
    }
    for (int i = 0; i < num; i++)
        n_char += my_putchar(get_digit_at_num(nb, num - i) + '0');
    return n_char;
}
