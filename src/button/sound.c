/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <SFML/Audio/SoundBuffer.h>
#include "my_world.h"
#include "my_button.h"

static sound_s create_sound(char *filepath)
{
    sound_s my_sound = {NULL, NULL};

    my_sound.sound = sfSound_create();
    if (my_sound.sound == NULL)
        return my_sound;
    my_sound.buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(my_sound.sound, my_sound.buffer);
    return my_sound;
}

static void sound_filler(button_manage_t *button, sound_s sound)
{
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
    button->tree->sound = sound;
    button->angle_x_plus->sound = sound;
    button->angle_y_plus->sound = sound;
    button->angle_x_min->sound = sound;
    button->angle_y_min->sound = sound;
}

int sound_set(button_manage_t *button)
{
    sound_s sound = create_sound(BUTT_DEFAULT_SOUND);

    button->exit->sound = create_sound(BUTT_EXIT_SOUND);
    if (!sound.buffer || !button->exit->sound.buffer)
        return EXIT_ERROR;
    sound_filler(button, sound);
    return EXIT_SUCCESS;
}