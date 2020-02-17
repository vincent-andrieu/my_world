/*
** EPITECH PROJECT, 2019
** framebuffer_destroy
** File description:
** destroy a framebuffer
*/

#include <stdlib.h>
#include "graph.h"

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}