#include "ft_btree.h"
#include <io.h>
#include <stdlib.h>

void    ft_putnbr(int);

int ft_nbrcmp(void* n1, void* n2)
{
    return *(int*)(n1) - *(int*)(n2);
}

void ft_print_item(void* item, int level, int isFirstElem)
{
    if (isFirstElem) {
        _write(1, "Level ", 6);
        ft_putnbr(level);
        _write(1, ": ", 2);
    }
    else {
        ft_putnbr(*(int*)(item));
        _write(1, " ", 1);
    }
}

int main()
{
    t_btree* btree = NULL;
    int num[] = { 20, 8, 22, 4, 12, 10, 14 };
    int i = -1;

    while (++i < 7)
        btree_insert_data(&btree, &num[i], ft_nbrcmp);

    btree_apply_by_level(btree, ft_print_item);
    btree_delete_tree(btree);
    return 0;
}