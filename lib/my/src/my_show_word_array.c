/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** put array in a string
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    if (!tab)
        return 0;
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
