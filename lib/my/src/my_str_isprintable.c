/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** is a printable string
*/

int my_str_isprintable(char const *str)
{
    if (*str == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32 && str[i] > 126)
            return 0;
    return 1;
}
