/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** display an image in a window
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"
#include "graph.h"
#include "my_radar.h"

bool does_kill_prog(assets_t *assets, entities_t *entities)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(assets->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyReleased
        && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(assets->window);
            return true;
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyL)
            toggle_hitboxes(entities->planes);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyS)
            toggle_sprites(entities->planes, entities->towers);
    }
    return false;
}

static int show_window(assets_t *assets)
{
    sfEvent event;
    int exit_value;

    srand(time(NULL));
    exit_value = my_world(assets);
    while (sfRenderWindow_pollEvent(assets->window, &event))
        if (event.type == sfEvtClosed
        || event.key.code == sfKeyEscape)
            sfRenderWindow_close(assets->window);
    sfTexture_updateFromPixels(assets->texture, assets->framebuffer->pixels,
                                WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    sfRenderWindow_clear(assets->window, sfBlack);
    sfRenderWindow_drawSprite(assets->window, assets->sprite, NULL);
    sfRenderWindow_display(assets->window);
    return exit_value;
}

static int prepare_window(sfVideoMode mde, assets_t *assets)
{
    int exit_value = -1;

    if (assets == NULL)
        return EXIT_ERROR;
    assets->window = sfRenderWindow_create(mde, NAME, sfResize | sfClose, NULL);
    assets->texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    assets->sprite = sfSprite_create();
    assets->framebuffer = framebuffer_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (assets->window == NULL || assets->texture == NULL)
        return EXIT_ERROR;
    sfSprite_setTexture(assets->sprite, assets->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(assets->window, 30);
    if (sfRenderWindow_isOpen(assets->window))
        exit_value = show_window(assets);
    framebuffer_destroy(assets->framebuffer);
    sfSprite_destroy(assets->sprite);
    sfTexture_destroy(assets->texture);
    sfRenderWindow_destroy(assets->window);
    free(assets);
    return exit_value;
}

int main(int argc, char **argv)
{
    if (!my_strcmp(argv[1], "-h"))
        return usage(EXIT_SUCCESS, argv[0]);
    if (argc != 1) {
        my_put_error_str(MSG_INVALID_ARG_NBR);
        return EXIT_INVALID_ARG_NBR;
    }
    return prepare_window((sfVideoMode)
                {WINDOW_WIDTH, WINDOW_HEIGHT, 32}, malloc(sizeof(assets_t)));
}