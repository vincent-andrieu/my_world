/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "my_world.h"

int my_world(assets_t *assets)
{
    sfVector2f **my_map;
    my_world_t *my_world = get_my_world();

    while (!does_kill_prog(assets)) {
        my_map = create_twod_map(my_world->map);
        if (!my_map)
            return EXIT_ERROR;
        draw_twod_map(assets->window, my_map);
        refresh_screen(assets);
        for (int i = 0; my_map[i]; i++)
            free(my_map[i]);
        free(my_map);
    }
    my_world_destroy(my_world);
    return EXIT_SUCCESS;
}