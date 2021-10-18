#include "ft_stock_par.h"

void ft_putaddr(void const*);
void ft_putstr(char const*);

int main(int ac, char* av[])
{
    t_stock_par* tab = ft_param_to_tab(ac, av);

    while (tab->str) {
        ft_putstr(tab->str);
        ft_putstr("<"); ft_putaddr((void*)tab->str); ft_putstr(">\n");
        ft_putstr(tab->copy);
        ft_putstr("<"); ft_putaddr((void*)tab->copy); ft_putstr(">\n");
        ++tab;
    }
    
    return 0;
}