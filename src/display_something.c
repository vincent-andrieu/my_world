/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

my_sprite_s get_sprite(void)
{
    my_sprite_s my_struct = {0};

    my_struct.sprite_kelp = sfSprite_create();
    my_struct.texture_kelp = sfTexture_createFromFile("./ressources/kelp.png", NULL);
    sfSprite_setTexture(my_struct.sprite_kelp, my_struct.texture_kelp, sfTrue);
    my_struct.sprite = sfSprite_create();
    my_struct.texture = sfTexture_createFromFile("./ressources/tree.png", NULL);
    sfSprite_setTexture(my_struct.sprite, my_struct.texture, sfTrue);
    my_struct.sprite_jaaj = sfSprite_create();
    my_struct.texture_jaaj =
    sfTexture_createFromFile("./ressources/player.jpg", NULL);
    sfSprite_setTexture(my_struct.sprite_jaaj, my_struct.texture_jaaj, sfTrue);
    my_struct.list = make_list();
    my_struct.select = false;
    return my_struct;
}

static void get_tree_select(assets_t *assets, sfVector2f **map,
    my_world_t *world, int (*my_func)(my_world_t *world, sfVector2i coords))
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(assets->window);

    for (int y = 0; y < world->scale.y; y++)
        for (int x = 0; x < world->scale.x; x++)
            if (map[y][x].x - mouse.x > -world->accuracy
            && map[y][x].x - mouse.x < world->accuracy
            && map[y][x].y - mouse.y > -world->accuracy
            && map[y][x].y - mouse.y < world->accuracy) {
                my_func(world, (sfVector2i) {x, y});
            }
}

static int destroy_it(my_world_t *world, sfVector2i coords)
{
    list_t *prev = world->tree.list;
    list_t *end;

    if (!prev)
        return 1;
    end = prev->next;
    while (end) {
        if (end->pos.x == coords.x && end->pos.y == coords.y) {
            prev->next = end->next;
            free(end);
            return 0;
        }
        prev = end;
        end = end->next;
    }
    return 1;
}

void my_tree_gest(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && my_world->tree.select)
        get_tree_select(assets, map, my_world, add_one);
    else if (sfMouse_isButtonPressed(sfMouseRight) && my_world->tree.select)
        get_tree_select(assets, map, my_world, destroy_it);
}