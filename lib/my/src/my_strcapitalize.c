/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** set first letters to capitals
*/

static int is_to(char str)
{
    if (str == ' ' || str == '-' || str == '+')
        return 1;
    else if (str >= '0' && str <= '9')
        return 0;
    return -1;
}

char *my_strcapitalize(char *str)
{
    int is_to_set = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i] >= 'a' && str[i] <= 'z' && is_to_set) {
            str[i] -= 32;
            is_to_set = 0;
        } else if (is_to(str[i]) != -1)
            is_to_set = is_to(str[i]);
    }
    return str;
}
