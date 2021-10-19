#include "ft_btree.h"
#include <io.h>
#include <stdlib.h>

void ft_putnbr(int);
void ft_putnbr_proxy(void* n)
{
    ft_putnbr(*(int*)(n));
    _write(1, " ", 1);
}

int ft_nbrcmp(void* n1, void* n2)
{
    return *(int*)(n1) - *(int*)(n2);
}

int main()
{
    int num[] = { 50, 30, 20, 40, 70, 60, 80 };
    t_btree* btree = NULL;
    int      i = -1;
    while (++i < 7)
        btree_insert_data(&btree, &num[i], ft_nbrcmp);

    int   ft = 42;
    void* res = NULL;
    res = btree_search_item(btree, &num[3], ft_nbrcmp);
    res ? ft_putnbr_proxy(res) : ft_putnbr(0);
    res = btree_search_item(btree, &ft, ft_nbrcmp);
    res ? ft_putnbr_proxy(res) : ft_putnbr(0);

    btree_delete_tree(btree);
    return 0;
}