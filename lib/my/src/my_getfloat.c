/*
** EPITECH PROJECT, 2019
** my_getfloat
** File description:
** get a float from string
*/

float my_getfloat(char *nbr)
{
    float num;
    float decimal;
    int i = 0;

    for (; nbr[i] != '.' && nbr[i] != '\0'; i++);
    if (nbr[i] == '.')
        nbr[i] = '\0';
    else
        return my_getnbr(nbr);
    num = my_getnbr(nbr);
    nbr += i;
    decimal = my_getnbr(nbr);
    while (decimal > 0.0)
        decimal / 10;
    return num + decimal;
}