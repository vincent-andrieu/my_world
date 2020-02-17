/*
** EPITECH PROJECT, 2019
** refresh_screen
** File description:
** refresh the screen
*/

#include <SFML/Graphics.h>
#include "graph.h"

void refresh_screen(assets_t *assets)
{
    sfTexture_updateFromPixels(assets->texture, assets->framebuffer->pixels,
                                WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(assets->window, assets->sprite, NULL);
    sfRenderWindow_display(assets->window);
}