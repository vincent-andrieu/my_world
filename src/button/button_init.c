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
    if (!but->exit || !but->restart || !but->zoom_in || !but->zoom_out ||
        !but->size_x_plus || !but->size_x_min || !but->size_y_plus ||
        !but->size_y_min || !but->up || !but->down || !but->left || !but->right)
        return EXIT_ERROR;
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

static int set_name_struct(button_manage_t *button)
{
    char *name[]= { "EXIT", "RESTART", "ZOOM +", "ZOOM -", "X +", "X -", "Y +",
                    "Y -", "UP", "DOWN", "LEFT", "RIGHT"};
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < 12; i++) {
        tmp = *(void **)manage;
        if (set_button_id(tmp, name[i], FONT_PATH, SIZE_CHAR) == 84)
            return EXIT_ERROR;
        manage = (void *)manage + 8;
    }
    return EXIT_SUCCESS;
}

static void set_clock(button_manage_t *button)
{
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < 12; i++) {
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