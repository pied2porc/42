#include "ft_ultimate_fight.h"
#include "ft_perso.h"
#include <io.h>

void ft_putstr(const char* s)
{
    int len = -1;
    while (s[++len]);
    _write(1, s, len);
}

const t_moves ft_get_move(int move)
{
    static t_moves const moves[max_moves] = {
    {"un coup de poing", 5},
    {"un coup de pied", 15},
    {"un coup de boule", 20},
    {"un coup de type 1", 13},
    {"un coup de second type", 3},
    {"un coup de 3eme type", 18},
    {"un coup de type 4", 9},
    {"un coup de 5eme type", 11},
    {"un coup de sixieme type", 13},
    {"un coup de type 7", 8},
    {"un tit coup", 6},
    {"un coup de type 9", 11},
    {"un coup de type 10", 9},
    {"un coup qui fait trop mal", 18},
    {"un coup de 12eme type", 10} };

    return moves[move];
}

void ft_fight(t_perso* atkr, t_perso* defr, int move)
{
    if (atkr->life <= 0 || defr->life <= 0)
        return;
    t_moves moves = ft_get_move(move);
    ft_putstr(atkr->name);
    ft_putstr(" donne ");
    ft_putstr(moves.type);
    ft_putstr(" a ");
    ft_putstr(defr->name);
    ft_putstr(".\n");

    defr->life -= moves.hit;
    if (defr->life <= 0) {
        ft_putstr(defr->name);
        ft_putstr(" est mort.\n");
    }
}