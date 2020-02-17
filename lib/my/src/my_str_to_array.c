/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** convert str to word array
*/

#include <stdlib.h>
#include <stdbool.h>

int my_strlen(char const *str);

char *my_strndup(char const *src, int n);

static int get_size(char const *str,
                            bool (*is_split_char)(char const c),
                            bool keep_splits)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (i > 0 && !is_split_char(str[i - 1]) && is_split_char(str[i]))
            count++;
    if (keep_splits)
        for (int i = 0; str[i] != '\0'; i++)
            count += is_split_char(str[i]) ? 1 : 0;
    count += is_split_char(str[my_strlen(str) - 1]) ? 1 : 2;
    return count;
}

static char *rm_unalphanum(char *str, bool (*is_split_char)(char const c))
{
    int i;

    for (i = 0; is_split_char(str[i]); i++);
    if (i < my_strlen(str))
        str += i;
    return str;
}

static int rm_first_chars(bool keep_splits,
                        bool (*is_split_char)(char const c),
                        char const *str)
{
    int i = 0;

    if (!keep_splits)
        for (; is_split_char(str[i]); i++);
    return i;
}

static void do_split(char const *str,
                        bool (*is_split_char)(char const c),
                        bool keep_splits, char **tab)
{
    int word = 0;

    for (int i = 1; i <= my_strlen(str); i++)
        if ((!keep_splits && !is_split_char(str[i - 1])
            && is_split_char(str[i]))
            || (keep_splits && (is_split_char(str[i])
            || (i > 0 && is_split_char(str[i - 1]))
            || i == my_strlen(str)))) {
            tab[word] = my_strndup(str, i);
            str += i;
            word++;
            if (!keep_splits)
                str = rm_unalphanum((char *) str, is_split_char);
            i = 0;
        }
    tab[word] = NULL;
}

char **my_str_to_array(char const *str,
                        bool (*is_split_char)(char const c),
                        bool keep_splits)
{
    char **tab;

    if (str == NULL || str[0] == '\0')
        return NULL;
    str += rm_first_chars(keep_splits, is_split_char, str);
    tab = malloc(sizeof(char *) * get_size(str, is_split_char, keep_splits));
    do_split(str, is_split_char, keep_splits, tab);
    return tab;
}