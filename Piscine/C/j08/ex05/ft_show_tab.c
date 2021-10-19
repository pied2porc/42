#include "ft_stock_par.h"
#include <io.h>

void ft_putstr(char const* str)
{
    if (!str) return;

    int i = -1;
    while (str[++i]);
    _write(1, str, i);
}

void ft_putnbr(int n)
{
    if (n >= 10) {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    if (n < 10)
        ft_putchar(n % 10 + '0');
}

void ft_show_tab(t_stock_par* par)
{
    while (par->str) {
        ft_putstr(par->str);
        ft_putchar('\n');
        ft_putnbr(par->size_param);
        ft_putchar('\n');
        int i = -1;
        while (par->tab && par->tab[++i]) {
            ft_putstr(par->tab[i]);
            ft_putchar('\n');
        }
        ++par;
    }
}