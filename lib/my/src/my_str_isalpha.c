/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** is an alphabetical string
*/

static int is_alpha(char str)
{
    if (str >= 'A' && str <= 'Z')
        return 1;
    if (str >= 'a' && str <= 'z')
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!is_alpha(str[i]))
            return 0;
    return 1;
}
