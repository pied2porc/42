#include "ft_door.h"
#include <io.h>

void ft_putstr(char const* str)
{
    int i = -1;
    while (str[++i]);
    _write(1, str, i);
}

void open_door(t_door* door)
{
    ft_putstr("Door opening...\n");
    door->state = OPEN;
}

void close_door(t_door* door)
{
    ft_putstr("Door closing...\n");
    door->state = CLOSE;
}

ft_bool is_door_open(t_door* door)
{
    ft_putstr("Door is open ?\n");
    return (door->state == OPEN);
}

ft_bool is_door_close(t_door* door)
{
    ft_putstr("Door is close ?\n");
    return (door->state == CLOSE);
}