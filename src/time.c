/*
** EPITECH PROJECT, 2019
** time
** File description:
** time
*/

#include <unistd.h>
#include <fcntl.h>

unsigned int my_time(void)
{
    int read_size;
    unsigned int my_rand = 0;
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return 0;
    read_size = read(fd, &my_rand, sizeof(my_rand));
    if (read_size == -1)
        return 0;
    close(fd);
    return my_rand;
}