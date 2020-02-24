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
#include "my_button.h"

void free_my_map(sfVector2f **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

static int end_of_world(sfMusic *song, my_world_t *my_world,
    button_manage_t *button)
{
    destroy_struct(button);
    song_destroy(song);
    my_world_destroy(my_world);
    return EXIT_SUCCESS;
}

static int game(assets_t *assets, my_world_t **my_world,
                button_manage_t *button)
{
    sfVector2f **my_map;

    refresh_struct(button, assets);
    display_struct(button, assets);
    if (button_effect(my_world, button, assets) != EXIT_SUCCESS)
        return EXIT_ERROR;
    map_stay_in_window(*my_world);
    my_map = create_twod_map((*my_world)->map, *my_world);
    if (!my_map)
        return EXIT_ERROR;
    edit_map(assets->window, *my_world, my_map);
    draw_twod_map(assets, my_map, *my_world);
    free_my_map(my_map);
    return EXIT_SUCCESS;
}

int my_world(assets_t *assets)
{
    my_world_t *my_world = get_my_world();
    sfMusic *song = start_song();
    button_manage_t *button = get_button_manage();

    if (!my_world)
        return EXIT_ERROR;
    while (!does_kill_prog(assets, my_world))
        if (game(assets, &my_world, button) != EXIT_SUCCESS)
            return EXIT_ERROR;
    return end_of_world(song, my_world, button);
}