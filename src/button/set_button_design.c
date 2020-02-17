/*
** EPITECH PROJECT, 2019
** my_button
** File description:
** my_button
*/

#include "my_button.h"

void set_button_ispressed(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size)
{
    sfRectangleShape_setOutlineThickness(my_button->button_ispressed,
        line_front_size);
    sfRectangleShape_setOutlineColor(my_button->button_ispressed, front);
    sfRectangleShape_setFillColor(my_button->button_ispressed, back);
}

void set_button_in(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size)
{
    sfRectangleShape_setOutlineThickness(my_button->button_in, line_front_size);
    sfRectangleShape_setOutlineColor(my_button->button_in, front);
    sfRectangleShape_setFillColor(my_button->button_in, back);
}

void set_button(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size)
{
    sfRectangleShape_setOutlineThickness(my_button->button, line_front_size);
    sfRectangleShape_setOutlineColor(my_button->button, front);
    sfRectangleShape_setFillColor(my_button->button, back);
}

void set_text_position_in_button(my_button_t *my_button, sfVector2f pos)
{
    sfText_setPosition(my_button->text, pos);
}

void set_button_id(my_button_t *my_button, char *str, char *font_path,
    float size_char)
{
    my_button->text = sfText_create();
    my_button->font = sfFont_createFromFile(font_path);

    if (!str || !my_button->font)
        return;
    my_button->name = my_strdup(str);
    sfText_setString(my_button->text, str);
    sfText_setFont(my_button->text, my_button->font);
    sfText_setCharacterSize(my_button->text, size_char);
    sfText_setPosition(my_button->text, my_button->pos);
}