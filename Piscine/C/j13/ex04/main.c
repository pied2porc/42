#include "ft_btree.h"
#include <stdlib.h>
#include <io.h>

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
    int i = -1;
    while (++i < 7)
        btree_insert_data(&btree, &num[i], ft_nbrcmp);

    btree_apply_infix(btree, ft_putnbr_proxy);
    btree_delete_tree(btree);
    return 0;
}