/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** help box
*/

#include "my_world.h"

static sfSprite *get_help_box_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {1.1, 1});
    sfSprite_setPosition(sprite, (sfVector2f) {HELP_BOX_X, HELP_BOX_Y});
    return sprite;
}

static sfText *get_help_box_text(sfFont *font, int i)
{
    char *labels[] = {"Quit the game", "Set a flat map", "Zoom in the map",
        "Zoom out the map", "Increase the map size at the right",
        "Increase the map size at the left", "Increase the map size at the top",
        "Increase the map size at the bottom", "Move the map to the top",
        "Move the map to the bottom", "Move the map to the left",
        "Move the map to the right", "Load a new map", "Save the current map",
        "Change the edit mode", "Tree edit mode"
    };
    sfText *text = sfText_create();

    if (text == NULL)
        return NULL;
    sfText_setString(text, labels[i]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, HELP_BOX_CHAR_SIZE);
    sfText_setPosition(text, (sfVector2f) {HELP_BOX_X + 30, HELP_BOX_Y + 17});
    return text;
}

int set_help_box(button_manage_t *buttons)
{
    button_manage_t *manage = buttons;
    my_button_shape_t *button;
    sfFont *font = sfFont_createFromFile(FONT_PATH);
    sfTexture *texture = sfTexture_createFromFile("./ressources/help_box.png",
                                                    NULL);

    if (font == NULL || texture == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < 16; i++) {
        button = *(void **)manage;
        button->help_box.font = font;
        button->help_box.texture = texture;
        button->help_box.sprite = get_help_box_sprite(texture);
        button->help_box.text = get_help_box_text(font, i);
        if (button->help_box.sprite == NULL || button->help_box.text == NULL)
            return EXIT_ERROR;
        manage = (void *)manage + 8;
    }
    return EXIT_SUCCESS;
}

void display_help_box(button_manage_t *buttons, sfRenderWindow *window)
{
    button_manage_t *manage = buttons;
    my_button_shape_t *button;

    for (int i = 0; i < 16; i++) {
        button = *(void **)manage;
        if (button->toggle == 1) {
            sfRenderWindow_drawSprite(window, button->help_box.sprite, NULL);
            sfRenderWindow_drawText(window, button->help_box.text, NULL);
        }
        manage = (void *)manage + 8;
    }
}