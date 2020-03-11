/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

char *get_map(const char *filepath)
{
    struct stat st;
    char *buffer;
    int fd;
    int read_size;

    if (stat(filepath, &st) == -1)
        return NULL;
    fd = open(filepath, O_RDONLY);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (fd == -1 || buffer == NULL)
        return NULL;
    read_size = read(fd, buffer, st.st_size);
    if (read_size == -1)
        return NULL;
    buffer[read_size] = '\0';
    return buffer;
}