#include "ft_perso.h"
#include "ft_ultimate_fight.h"

int main()
{
    t_perso nina_myers;
    t_perso nicolas_bauer;

    nina_myers.name = "Zombie Nina Myers";
    nina_myers.life = 50;
    nicolas_bauer.name = "Nicolas Bauer";
    nicolas_bauer.life = 50;

    ft_fight(&nicolas_bauer, &nina_myers, KICK);
    ft_fight(&nina_myers, &nicolas_bauer, PUNCH);
    ft_fight(&nicolas_bauer, &nina_myers, HEADBUTT);
    ft_fight(&nina_myers, &nicolas_bauer, KICK1);
    ft_fight(&nicolas_bauer, &nina_myers, KICK6);
    ft_fight(&nina_myers, &nicolas_bauer, KICK11);
    ft_fight(&nina_myers, &nicolas_bauer, KICK8);
    ft_fight(&nicolas_bauer, &nina_myers, HEADBUTT);

    return 0;
}