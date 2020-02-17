/*
** EPITECH PROJECT, 2019
** my_str_isalphanum
** File description:
** is an alphanumeric string
*/

static int is_alphanum(char const str)
{
    if (str >= '0' && str <= '9')
        return 1;
    if (str >= 'A' && str <= 'Z')
        return 1;
    if (str >= 'a' && str <= 'z')
        return 1;
    return 0;
}

int my_str_isalphanum(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!is_alphanum(str[i]))
            return 0;
    return 1;
}
