/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n char from a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        if (i < n)
            dest[i] = src[i];
        else
            break;
    }
    dest[i] = '\0';
    return dest;
}
