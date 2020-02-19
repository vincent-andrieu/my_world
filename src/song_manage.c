/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

sfMusic *start_song(void)
{
    sfMusic *song = sfMusic_createFromFile("./ressources/song.ogg");

    sfMusic_setVolume(song, 80);
    sfMusic_setLoop(song, sfTrue);
    sfMusic_play(song);
    return song;
}

void song_destroy(sfMusic *song)
{
    sfMusic_stop(song);
    sfMusic_destroy(song);
}