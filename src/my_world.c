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

static void free_my_map(sfVector2f **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

int my_world(assets_t *assets)
{
    my_world_t *my_world = get_my_world();
    sfVector2f **my_map;
    sfMusic *song = start_song();

    if (!my_world)
        return EXIT_ERROR;
    my_world->zoom = 1;
    while (!does_kill_prog(assets, my_world)) {
        map_stay_in_window(my_world);
        my_map = create_twod_map(my_world->map, my_world);
        if (!my_map)
            return EXIT_ERROR;
        edit_map(assets->window, my_world, my_map);
        draw_twod_map(assets, my_map);
    }
    song_destroy(song);
    free_my_map(my_map);
    my_world_destroy(my_world);
    return EXIT_SUCCESS;
}