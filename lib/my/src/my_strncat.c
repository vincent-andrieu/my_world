/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** write n char of a string following another string
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    for (int i = 0; src[i] != '\0' && i < nb; i++) {
        dest[my_strlen(dest)] = src[i];
        dest[my_strlen(dest) + 1] = '\0';
    }
    return dest;
}
