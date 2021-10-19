#include "ft_perso.h"
#include "ft_fight.h"

int main()
{
    t_perso anastacia;
    t_perso nicolas_bauer;

    anastacia.name = "Anastacia";
    anastacia.life = 25;
    nicolas_bauer.name = "Nicolas Bauer";
    nicolas_bauer.life = 25;

    ft_fight(&nicolas_bauer, &anastacia, KICK);
    ft_fight(&anastacia, &nicolas_bauer, PUNCH);
    ft_fight(&nicolas_bauer, &anastacia, HEADBUTT);

    return 0;
}