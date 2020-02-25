/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "my_button.h"

void display_struct(button_manage_t *button, assets_t *assets)
{
    button_display(button->exit, assets->window);
    button_display(button->restart, assets->window);
    button_display(button->zoom_in, assets->window);
    button_display(button->zoom_out, assets->window);
    button_display(button->size_x_plus, assets->window);
    button_display(button->size_x_min, assets->window);
    button_display(button->size_y_plus, assets->window);
    button_display(button->size_y_min, assets->window);
    button_display(button->up, assets->window);
    button_display(button->down, assets->window);
    button_display(button->left, assets->window);
    button_display(button->right, assets->window);
    button_display(button->load, assets->window);
    button_display(button->save, assets->window);
    button_display(button->tools, assets->window);
}

void destroy_struct(button_manage_t *button)
{
    button_manage_t *manage = button;
    my_button_shape_t *tmp;

    for (int i = 0; i < NB_TEXTURE; i++)
        sfTexture_destroy(button->exit->texture[i]);
    free(button->exit->texture);
    sfSound_destroy(button->exit->sound.sound);
    sfSoundBuffer_destroy(button->exit->sound.buffer);
    sfSound_destroy(button->restart->sound.sound);
    sfSoundBuffer_destroy(button->restart->sound.buffer);
    for (int i = 0; i < 15; i++) {
        tmp = *(void **)manage;
        button_shape_destroy(tmp);
        manage = (void *)manage + 8;
    }
    free(button);
}

void refresh_struct(button_manage_t *button, assets_t *assets)
{
    button_refresh_stat(button->exit, assets->window);
    button_refresh_stat(button->restart, assets->window);
    button_refresh_stat(button->zoom_in, assets->window);
    button_refresh_stat(button->zoom_out, assets->window);
    button_refresh_stat(button->size_x_plus, assets->window);
    button_refresh_stat(button->size_x_min, assets->window);
    button_refresh_stat(button->size_y_plus, assets->window);
    button_refresh_stat(button->size_y_min, assets->window);
    button_refresh_stat(button->up, assets->window);
    button_refresh_stat(button->down, assets->window);
    button_refresh_stat(button->left, assets->window);
    button_refresh_stat(button->right, assets->window);
    button_refresh_stat(button->load, assets->window);
    button_refresh_stat(button->save, assets->window);
    button_refresh_stat(button->tools, assets->window);
}

bool button_ispressed(my_button_shape_t *my_button)
{
    if (my_button->toggle == 2) {
        sfText_setPosition(my_button->text, (sfVector2f)
            {my_button->pos.x + 55, my_button->pos.y + 40});
        return true;
    }
    sfText_setPosition(my_button->text, (sfVector2f)
        {my_button->pos.x + 55, my_button->pos.y + 30});
    return false;
}

int set_button_id(my_button_shape_t *my_button, char *str, char *font_path,
    float size_char)
{
    sfVector2f pos = {my_button->pos.x + 55, my_button->pos.y + 30};
    my_button->text = sfText_create();
    my_button->font = sfFont_createFromFile(font_path);

    if (!str || !my_button->font)
        return EXIT_ERROR;
    my_button->name = my_strdup(str);
    if (!my_button->name)
        return EXIT_ERROR;
    sfText_setString(my_button->text, str);
    sfText_setFont(my_button->text, my_button->font);
    sfText_setCharacterSize(my_button->text, size_char);
    sfText_setPosition(my_button->text, pos);
    return EXIT_SUCCESS;
}