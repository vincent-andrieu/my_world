/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** print int from string
*/

int my_strlen(char const *str);

static int get_num(char *list, char option)
{
    int power = 1;
    int num = 0;
    int n = 0;

    for (int i = my_strlen(list) - 1; i >= 0; i--) {
        if (list[i] >= '0' && list[i] <= '9') {
            num += (list[i] - 48) * power;
            power *= 10;
            n++;
        }
    }
    if (option == 'n')
        return n;
    return num;
}

static int blacklist_charac(char c)
{
    for (int i = 'a'; i <= 'z'; i++)
        if (i == c)
            return 1;
    for (int i = 'A'; i <= 'Z'; i++)
        if (i == c)
            return 1;
    return 0;
}

static void prepare_list(char const *str, char *list)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            list[x] = str[i];
            x++;
            list[x] = '\0';
        }
        if (blacklist_charac(str[i])) {
            list[i] = '\0';
            break;
        }
    }
}

static int is_neg(char const *str)
{
    int neg = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-') {
            if (neg)
                neg = 0;
            else
                neg = 1;
        }
    return neg;
}

int my_getnbr(char const *str)
{
    char list[my_strlen(str)];
    int big_num = 0;
    int neg = 0;
    int num;
    int max_v = 1000000000;

    prepare_list(str, list);
    neg = is_neg(str);
    if (get_num(list, 'n') > 10)
        return 0;
    if (get_num(list, 'n') == 10)
        big_num = 1;
    num = get_num(list, 'd');
    if (neg)
        num = -num;
    if (big_num && ((num < max_v && neg == 0) || (num > -max_v && neg == 1)))
        return 0;
    return num;
}
