/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <SFML/Audio/SoundBuffer.h>
#include "my_world.h"
#include "my_button.h"

void sound_set(sound_s sound, button_manage_t *button)
{
    button->exit->sound = sound;
    button->restart->sound = sound;
    button->zoom_in->sound = sound;
    button->zoom_out->sound = sound;
    button->size_x_plus->sound = sound;
    button->size_x_min->sound = sound;
    button->size_y_plus->sound = sound;
    button->size_y_min->sound = sound;
    button->up->sound = sound;
    button->down->sound = sound;
    button->left->sound = sound;
    button->right->sound = sound;
    button->load->sound = sound;
    button->save->sound = sound;
    button->tools->sound = sound;
}

sound_s create_sound(void)
{
    sound_s my_sound;

    my_sound.sound = sfSound_create();
    my_sound.buffer = malloc(sizeof(sfSoundBuffer *));
    my_sound.buffer = sfSoundBuffer_createFromFile("./ressources/sound.ogg");
    sfSound_setBuffer(my_sound.sound, my_sound.buffer);
    return my_sound;
}