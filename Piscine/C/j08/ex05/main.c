#include "ft_stock_par.h"
#include <stdlib.h>
#include <stdio.h>

void ft_free_tab(t_stock_par* tab) {
    t_stock_par* cur = tab - 1;
    while ((++cur)->str) {
        free(cur->copy);
        while (*cur->tab) {
            free(*cur->tab);
            ++cur->tab;
        }
    }
    free(tab);
}

int main(int ac, char* av[])
{
    t_stock_par* par = ft_param_to_tab(ac, av);
    ft_show_tab(par);
    ft_free_tab(par);
    return 0;
}