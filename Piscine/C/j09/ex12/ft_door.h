#pragma once

#define CLOSE   0
#define OPEN    1

typedef int ft_bool;

typedef struct s_door {
    ft_bool state;
} t_door;

void    ft_putstr(char const*);
void    close_door(t_door*);
void    open_door(t_door*);
ft_bool is_door_open(t_door*);
ft_bool is_door_close(t_door*);