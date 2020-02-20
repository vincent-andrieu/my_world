/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "my_button.h"

static int my_fill_struct(button_manage_t *but)
{
    sfVector2f hit_box = {HIT_X, HIT_Y};

    but->exit = get_button_shape((sfVector2f) {TOOLS_X, 10}, hit_box);
    but->restart = get_button_shape((sfVector2f) {TOOLS_X, 110}, hit_box);
    but->zoom_in = get_button_shape((sfVector2f) {TOOLS_X, 210}, hit_box);
    but->zoom_out = get_button_shape((sfVector2f) {TOOLS_X, 310}, hit_box);
    but->size_x_plus = get_button_shape((sfVector2f) {TOOLS_X, 410}, hit_box);
    but->size_x_min = get_button_shape((sfVector2f) {TOOLS_X, 510}, hit_box);
    but->size_y_plus = get_button_shape((sfVector2f) {TOOLS_X, 610}, hit_box);
    but->size_y_min = get_button_shape((sfVector2f) {TOOLS_X, 710}, hit_box);
    but->up = get_button_shape((sfVector2f) {TOOLS_X, 810}, hit_box);
    but->down = get_button_shape((sfVector2f) {TOOLS_X, 910}, hit_box);
    but->left = get_button_shape((sfVector2f) {TOOLS_X - 250, 10}, hit_box);
    but->right = get_button_shape((sfVector2f) {TOOLS_X - 250, 110}, hit_box);

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
}

static void set_name_struct(button_manage_t *button)
{
    set_button_id(button->exit, "EXIT", FONT_PATH, SIZE_CHAR);
    set_button_id(button->restart, "RESTART", FONT_PATH, SIZE_CHAR);
    set_button_id(button->zoom_in, " ZOOM +", FONT_PATH, SIZE_CHAR);
    set_button_id(button->zoom_out, "ZOOM -", FONT_PATH, SIZE_CHAR);
    set_button_id(button->size_x_plus, "X +", FONT_PATH, SIZE_CHAR);
    set_button_id(button->size_x_min, "X -", FONT_PATH, SIZE_CHAR);
    set_button_id(button->size_y_plus, "Y +", FONT_PATH, SIZE_CHAR);
    set_button_id(button->size_y_min, "Y -", FONT_PATH, SIZE_CHAR);
    set_button_id(button->up, "UP", FONT_PATH, SIZE_CHAR);
    set_button_id(button->down, "DOWN", FONT_PATH, SIZE_CHAR);
    set_button_id(button->left, "LEFT", FONT_PATH, SIZE_CHAR);
    set_button_id(button->right, "RIGHT", FONT_PATH, SIZE_CHAR);
}

button_manage_t *get_button_manage(void)
{
    button_manage_t *button = malloc(sizeof(button_manage_t));
    sfTexture **texture;

    if (!button)
        return NULL;
    texture = malloc(sizeof(sfTexture *) * NB_TEXTURE);
    if (!texture)
        return NULL;
    if (my_fill_struct(button) == EXIT_ERROR)
        return NULL;
    texture[0] = sfTexture_createFromFile("./ressources/button_pressed.png", NULL);
    texture[1] = sfTexture_createFromFile("./ressources/button_over.png", NULL);
    texture[2] = sfTexture_createFromFile("./ressources/button.png", NULL);
    texture_set(texture, button);
    set_name_struct(button);
    return button;
}