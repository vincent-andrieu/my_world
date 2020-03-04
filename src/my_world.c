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

static sfSprite *init_background(void)
{
    sfSprite *background = sfSprite_create();

    sfSprite_setTexture(background,
        sfTexture_createFromFile("./ressources/background.jpg", NULL), sfTrue);
    sfSprite_setScale(background, (sfVector2f) {1, 1.2});
    return background;
}

static sfVector2f **game(assets_t *assets, my_world_t **my_world,
                button_manage_t *button, sfVector2f **my_map)
{
    refresh_struct(button, assets);
    edit_map(assets->window, *my_world, my_map);
    draw_twod_map(assets, my_map, *my_world);
    my_tree_gest(assets, my_map, *my_world);
    display_struct(button, assets);
    display_help_box(button, assets->window);
    display_precision((*my_world)->accuracy, assets);
    if (button_effect(my_world, button, assets) == EXIT_ERROR)
        return NULL;
    if (as_seconds(sfClock_getElapsedTime((*my_world)->clock)) > TIME_BUT) {
        free_my_map(my_map);
        my_map = create_twod_map((*my_world)->map, *my_world);
        refresh_screen(assets);
        sfRenderWindow_clear(assets->window, sfBlack);
        sfClock_restart((*my_world)->clock);
    }
    return my_map;
}

int my_world(assets_t *assets, char *filepath)
{
    my_world_t *my_world = get_my_world();
    sfMusic *song = start_song();
    button_manage_t *button = get_button_manage();
    sfSprite *background = init_background();
    sfVector2f **my_map = create_twod_map(my_world->map, my_world);

    if (!my_map || !my_world || load_map(&my_world, filepath == NULL ?
    get_input("Loading filepath") : my_strdup(filepath)) == EXIT_ERROR)
        return EXIT_ERROR;
    display_precision(my_world->accuracy, assets);
    while (!does_kill_prog(assets, my_world)) {
        sfRenderWindow_drawSprite(assets->window, background, NULL);
        my_map = game(assets, &my_world, button, my_map);
        if (my_map == NULL)
            return EXIT_ERROR;
    }
    sfSprite_destroy(background);
    if (final_save(my_world, START_SAVE_NBR) == EXIT_ERROR)
        return EXIT_ERROR;
    return end_of_world(song, my_world, button);
}