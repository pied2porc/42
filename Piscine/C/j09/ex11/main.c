#include "ft_perso.h"

int main()
{
    t_perso jack;

    jack.name = _strdup("Jack");
    jack.life = 100.0;
    jack.age = 42;
    jack.profession = SAVE_THE_WORLD;
    return 0;
}