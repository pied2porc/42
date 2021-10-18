#pragma once
#include <string.h>

#define SAVE_THE_WORLD  42

typedef struct s_perso {
    char const* name;
    double      life;
    int         age;
    int         profession;
} t_perso;