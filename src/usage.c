/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** my_radar usage
*/

#include "my.h"
#include "my_world.h"

int usage(int exit_value, char *binary_name)
{
    my_putstr("3D World simulation\n\nUSAGE\n\t");
    my_putstr(binary_name);
    my_putstr("\n\nOPTIONS\n\t-h\tprint the usage and quit.\n");
    return exit_value;
}

sfSprite *init_background(void)
{
    sfSprite *background = sfSprite_create();

    sfSprite_setTexture(background,
        sfTexture_createFromFile("./ressources/background.jpg", NULL), sfTrue);
    sfSprite_setScale(background, (sfVector2f) {1, 1.2});
    return background;
}