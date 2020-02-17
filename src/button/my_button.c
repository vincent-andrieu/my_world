/*
** EPITECH PROJECT, 2019
** my_button
** File description:
** my_button
*/

#include "my_button.h"

my_button_t *get_button(sfVector2f scale, sfVector2f pos)
{
    my_button_t *my_button = malloc(sizeof(my_button_t));

    if (!my_button)
        return NULL;
    my_button->button = sfRectangleShape_create();
    my_button->button_in = sfRectangleShape_create();
    my_button->button_ispressed = sfRectangleShape_create();
    my_button->scale = scale;
    my_button->pos = pos;
    sfRectangleShape_setPosition(my_button->button, pos);
    sfRectangleShape_setSize(my_button->button, scale);
    sfRectangleShape_setPosition(my_button->button_in, pos);
    sfRectangleShape_setSize(my_button->button_in, scale);
    sfRectangleShape_setPosition(my_button->button_ispressed, pos);
    sfRectangleShape_setSize(my_button->button_ispressed, scale);
    my_button->tooggle = 0;
    my_button->name = NULL;
    return my_button;
}

void button_refresh_stat(my_button_t *my_button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= my_button->pos.x &&
        mouse_pos.x <= my_button->pos.x + my_button->scale.x) {
        if (mouse_pos.y >= my_button->pos.y &&
            mouse_pos.y <= my_button->pos.y + my_button->scale.y) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                my_button->tooggle = 2;
            else my_button->tooggle = 1;

        }
    }
    else my_button->tooggle = 0;
}

void button_display(my_button_t *my_button, sfRenderWindow *window)
{
    if (my_button->tooggle == 0)
        sfRenderWindow_drawRectangleShape(window, my_button->button, NULL);
    if (my_button->tooggle == 1)
        sfRenderWindow_drawRectangleShape(window, my_button->button_in, NULL);
    if (my_button->tooggle == 2)
        sfRenderWindow_drawRectangleShape(window,
            my_button->button_ispressed, NULL);
    if (my_button->name)
        sfRenderWindow_drawText(window, my_button->text, NULL);
}

void button_detroy(my_button_t *my_button)
{
    if (my_button->name) {
        free(my_button->name);
        sfFont_destroy(my_button->font);
        sfText_destroy(my_button->text);
    }
    sfRectangleShape_destroy(my_button->button);
    sfRectangleShape_destroy(my_button->button_in);
    sfRectangleShape_destroy(my_button->button_ispressed);
    free(my_button);
}

bool button_ispressed(my_button_t *my_button)
{
    if (my_button->tooggle == 2)
        return true;
    return false;
}