#include "ft_fight.h"
#include "ft_perso.h"
#include <io.h>

void ft_putstr(char const* s)
{
    int len = -1;
    while (s[++len]);
    _write(1, s, len);
}

void ft_fight(t_perso* atkr, t_perso* defr, int move)
{
    if (atkr->life <= 0 || defr->life <= 0)
        return;
    ft_putstr(atkr->name);
    ft_putstr(" donne ");
    switch (move) {
    case PUNCH:
        defr->life -= 5;
        ft_putstr("un coup de poing");
        break;
    case KICK:
        defr->life -= 15;
        ft_putstr("un coup de pied");
        break;
    case HEADBUTT:
        defr->life -= 20;
        ft_putstr("un coup de boule");
        break;
    }
    ft_putstr(" a ");
    ft_putstr(defr->name);
    ft_putstr(".\n");

    if (defr->life <= 0) {
        ft_putstr(defr->name);
        ft_putstr(" est mort.\n");
    }
}