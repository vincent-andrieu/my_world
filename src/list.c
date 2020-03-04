/*
** EPITECH PROJECT, 2019
** liste chaine
** File description:
** liste chaine
*/

#include "my_world.h"

list_t *make_list(void)
{
    list_t *start = malloc(sizeof(list_t));

    if (!start)
        return NULL;
    start->next = NULL;
    start->pos = (sfVector2i) {0, 0};
    return start;
}

int add_one(my_world_t *my_world, sfVector2i coords)
{
    list_t *end = my_world->tree.list;

    while (end->next)
        end = end->next;
    end->next = malloc(sizeof(list_t));
    if (!end->next)
        return EXIT_ERROR;
    end->next->next = NULL;
    end->next->pos = coords;
    return EXIT_SUCCESS;
}

void distroy(list_t *list)
{
    list_t *temp = list;
    list_t *end = list;

    while (end) {
        end = temp->next;
        free(temp);
        temp = end;
    }
}