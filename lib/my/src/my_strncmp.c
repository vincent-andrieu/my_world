/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare 2 strings at n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1[0] != '\0' && s2[0] == '\0')
        return 1;
    if (s1[0] == '\0' && s2[0] != '\0')
        return -1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (i + 1 < n && s1[i] == s2[i] && s1[i + 1] == 0 && s2[i + 1] != 0)
            return -1;
        if (i + 1 < n && s1[i] == s2[i] && s2[i + 1] == 0 && s1[i + 1] != 0)
            return 1;
    }
    return 0;
}
