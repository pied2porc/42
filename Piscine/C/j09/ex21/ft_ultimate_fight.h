#pragma once
#include "ft_perso.h"

enum e_moves {
    PUNCH, KICK, HEADBUTT,
    KICK1, KICK2, KICK3,
    KICK4, KICK5, KICK6,
    KICK7, KICK8, KICK9,
    KICK10, KICK11, KICK12,
    max_moves
};

typedef struct s_moves {
    char const* type;
    int         hit;
} t_moves;

void ft_fight(t_perso*, t_perso*, int);
void ft_putstr(char const*);