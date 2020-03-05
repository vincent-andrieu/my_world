/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

dog_t get_dog(void)
{
    dog_t dog = {0};

    dog.sprite = sfSprite_create();
    dog.texture = sfTexture_createFromFile("./ressources/dog.png", NULL);
    sfSprite_setTexture(dog.sprite, dog.texture, sfTrue);
    dog.status = true;
    dog.clock = sfClock_create();
    dog.pos = (sfVector2i) {10, 10};
    return dog;
}

static void dog_move(my_world_t *my_world, sfVector2i move, bool *tab)
{
    if (tab[0] && tab[1]) {
        if (rand() % 2 == 0)
            my_world->dog.pos.x += move.x;
        else
            my_world->dog.pos.y += move.y;
        return;
    }
    if (move.x > 0)
        my_world->dog.pos.x++;
    else if (move.x < 0)
        my_world->dog.pos.x--;
    else
        if (move.y > 0)
            my_world->dog.pos.y++;
        else if (move.y < 0)
            my_world->dog.pos.y--;
}

void dog_finder(my_world_t *my_world)
{
    bool tab[2];
    sfVector2i move = {0};

    if (as_seconds(sfClock_getElapsedTime(my_world->dog.clock)) < 0.2)
        return;
    sfClock_restart(my_world->dog.clock);
    move.x = my_world->tree.list->pos.x - (my_world->dog.pos.x - 1);
    move.y = my_world->tree.list->pos.y - (my_world->dog.pos.y - 1);
    tab [0] = (move.x != 0) ? true : false;
    tab [1] = (move.y != 0) ? true : false;
    move.x = (move.x < 0) ? -1 : (move.x > 0) ? 1 : 0;
    move.y = (move.y < 0) ? -1 : (move.y > 0) ? 1 : 0;
    if (!tab[0] && !tab[1])
        return;
    dog_move(my_world, move, tab);
}

void dog_destroy(dog_t dog)
{
    sfClock_destroy(dog.clock);
    sfTexture_destroy(dog.texture);
    sfSprite_destroy(dog.sprite);
}