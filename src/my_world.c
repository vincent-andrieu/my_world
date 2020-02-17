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
    my_button_t *b_one = get_button((sfVector2f) {100, 50}, (sfVector2f) {100, 50});

    set_button_ispressed(b_one, sfRed, sfBlue, 2.5);
    set_button_in(b_one, sfBlue, sfRed, 2.5);
    set_button(b_one, sfBlue, sfGreen, 2.5);
    set_button_id(b_one, "EXIT", "./src/other/ChunkfiveEx.ttf", 20);
    set_text_position_in_button(b_one, (sfVector2f) {b_one->pos.x + 20, b_one->pos.y + 15});

    if (!my_world)
        return EXIT_ERROR;
    my_world->zoom = 1;
    while (!does_kill_prog(assets, my_world)) {
        if (button_ispressed(b_one)) {
            sleep(2);
            break;
        }
        button_refresh_stat(b_one, assets->window);
        button_display(b_one, assets->window);
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
    button_detroy(b_one);
    return EXIT_SUCCESS;
}