/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** set a string to upcase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return str;
}
