/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** convert str to word array
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const *src, int n);

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

static int get_unalphanum(char const *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++)
        if (i > 0 && is_alphanum(str[i - 1]) && !is_alphanum(str[i]))
            count++;
    return count;
}

static char *rm_unalphanum(char *str)
{
    int i;

    for (i = 0; !is_alphanum(str[i]); i++);
    if (i < my_strlen(str))
        str += i;
    return str;
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int word = 0;
    int i;
    int last_char_malloc = !is_alphanum(str[my_strlen(str) - 1]) ? 1 : 2;

    if (str == NULL || str[0] == '\0')
        return NULL;
    for (i = 0; !is_alphanum(str[i]); i++);
    str += i;
    tab = malloc(sizeof(char *) * (get_unalphanum(str) + last_char_malloc));
    for (i = 0; i <= my_strlen(str); i++)
        if (is_alphanum(str[i - 1]) && !is_alphanum(str[i])) {
            tab[word] = my_strndup(str, i);
            str += i + 1;
            word++;
            str = rm_unalphanum((char *) str);
            i = 0;
        }
    tab[word] = NULL;
    return tab;
}
