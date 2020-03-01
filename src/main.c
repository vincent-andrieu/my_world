/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** display an image in a window
*/

#include <SFML/Graphics.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"
#include "graph.h"
#include "my_world.h"

static void event_manage(sfEvent event, my_world_t *my_world,
                        assets_t *assets)
{
    if ((event.type == sfEvtKeyPressed || sfMouse_isButtonPressed(sfMouseLeft))
    && as_seconds(sfClock_getElapsedTime(my_world->clock)) > TIME_BUT) {
        my_world->pres_pos = my_world->pos;
        event_set(event, my_world, assets);
        sfClock_restart(my_world->clock);
    }
    if (event.type == sfEvtMouseWheelScrolled) {
        my_world->zoom += event.mouseWheelScroll.delta / MOUSE_SENSI;
        if (my_world->zoom < 0)
            my_world->zoom -= event.mouseWheelScroll.delta / MOUSE_SENSI;
    }
}

bool does_kill_prog(assets_t *assets, my_world_t *my_world)
{
    sfEvent event;

    if (!sfRenderWindow_isOpen(assets->window))
        return true;
    while (sfRenderWindow_pollEvent(assets->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyReleased
        && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(assets->window);
            return true;
        }
        event_manage(event, my_world, assets);
    }
    return false;
}

static int show_window(assets_t *assets, char *filepath)
{
    sfEvent event;
    int exit_value;

    srand(time(NULL));
    exit_value = my_world(assets, filepath);
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

static int prepare_window(sfVideoMode mde, assets_t *assets, char *filepath)
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
        exit_value = show_window(assets, filepath);
    framebuffer_destroy(assets->framebuffer);
    sfSprite_destroy(assets->sprite);
    sfTexture_destroy(assets->texture);
    sfRenderWindow_destroy(assets->window);
    free(assets);
    return exit_value;
}

int main(int argc, char **argv)
{
    if (argc >= 2 && !my_strcmp(argv[1], "-h"))
        return usage(EXIT_SUCCESS, argv[0]);
    if (argc > 2) {
        my_put_error_str(MSG_INVALID_ARG_NBR);
        return EXIT_INVALID_ARG_NBR;
    }
    return prepare_window((sfVideoMode) {WINDOW_WIDTH, WINDOW_HEIGHT, 32},
                        malloc(sizeof(assets_t)), argc == 2 ? argv[1] : NULL);
}