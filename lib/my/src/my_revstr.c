/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i <= len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return str;
}
