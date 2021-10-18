#include "ft_perso.h"

void      ft_putnbr(int);
void      ft_putstr(char const*);
t_perso** ft_decrypt(char const*);
void      ft_cleanup(t_perso**, t_perso**);

int main()
{
    char const* str = "21|Nom;22|Nom2;23|Nom3";
    t_perso**   tab = ft_decrypt(str);

    int i = -1;
    while (tab[++i]) {
        ft_putstr(tab[i]->name);
        ft_putstr("(");
        ft_putnbr(tab[i]->age);
        ft_putstr(")\n");
    }
    ft_cleanup(tab, tab + i);
    return 0;
}