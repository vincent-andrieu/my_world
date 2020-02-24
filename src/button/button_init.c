/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "my_button.h"

static int my_fill_struct(button_manage_t *button)
{
    sfVector2f coords[15] = {(sfVector2f) {TOOLS_X, 10}, (sfVector2f)
        {TOOLS_X, 110}, (sfVector2f) {TOOLS_X, 210}, (sfVector2f) {TOOLS_X,
            310}, (sfVector2f) {TOOLS_X, 410}, (sfVector2f) {TOOLS_X, 510},
        (sfVector2f) {TOOLS_X, 610}, (sfVector2f) {TOOLS_X, 710},
        (sfVector2f) {TOOLS_X, 810}, (sfVector2f) {TOOLS_X, 910},
        (sfVector2f) {TOOLS_X - 250, 10}, (sfVector2f) {TOOLS_X - 250, 110},
        (sfVector2f) {TOOLS_X - 250, 210}, (sfVector2f) {TOOLS_X - 250, 310},
        (sfVector2f) {TOOLS_X - 250, 410}
    };
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < 15; i++) {
        tmp = get_button_shape(coords[i], (sfVector2f) {HIT_X, HIT_Y});
        if (tmp == NULL)
            return EXIT_ERROR;
        *(void **)manage = tmp;
        manage = (void *)manage + 8;
    }
    return EXIT_SUCCESS;
}

static void texture_set(sfTexture **texture, button_manage_t *button)
{
    button->exit->texture = texture;
    button->restart->texture = texture;
    button->zoom_in->texture = texture;
    button->zoom_out->texture = texture;
    button->size_x_plus->texture = texture;
    button->size_x_min->texture = texture;
    button->size_y_plus->texture = texture;
    button->size_y_min->texture = texture;
    button->up->texture = texture;
    button->down->texture = texture;
    button->left->texture = texture;
    button->right->texture = texture;
    button->load->texture = texture;
    button->save->texture = texture;
    button->tools->texture = texture;
}

static int set_name_struct(button_manage_t *button)
{
    char *name[]= { "EXIT", "RESTART", "ZOOM +", "ZOOM -", "X +", "X -", "Y +",
                    "Y -", "UP", "DOWN", "LEFT", "RIGHT", "LOAD", "SAVE",
                    "TOOLS"};
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < 15; i++) {
        tmp = *(void **)manage;
        if (set_button_id(tmp, name[i], FONT_PATH, SIZE_CHAR) != EXIT_SUCCESS)
            return EXIT_ERROR;
        manage = (void *)manage + 8;
    }
    return EXIT_SUCCESS;
}

static void set_clock(button_manage_t *button)
{
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < 15; i++) {
        tmp = *(void **)manage;
        tmp->clock_start = sfClock_create();
        tmp->is_pressed = false;
        tmp->is_activate = false;
        manage = (void *)manage + 8;
    }

}

button_manage_t *get_button_manage(void)
{
    button_manage_t *button = malloc(sizeof(button_manage_t));
    sfTexture **tex;

    if (!button)
        return NULL;
    tex = malloc(sizeof(sfTexture *) * NB_TEXTURE);
    if (!tex)
        return NULL;
    if (my_fill_struct(button) == EXIT_ERROR)
        return NULL;
    tex[0] = sfTexture_createFromFile("./ressources/button_pressed.png", NULL);
    tex[1] = sfTexture_createFromFile("./ressources/button_over.png", NULL);
    tex[2] = sfTexture_createFromFile("./ressources/button.png", NULL);
    texture_set(tex, button);
    if (set_name_struct(button) == EXIT_ERROR)
        return NULL;
    set_clock(button);
    return button;
}