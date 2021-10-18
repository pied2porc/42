#include "ft_btree.h"
#include <io.h>

void ft_putnbr(int);
void ft_putnbr_proxy(void* n)
{
    ft_putnbr(*(int*)(n));
    _write(1, " ", 1);
}

int main()
{
    int num[] = { 10, 8, 5, 3, 1, 2 };
    t_btree* btree1 = btree_create_node(&num[0]);
    t_btree* btree2 = btree_create_node(&num[1]);
    t_btree* btree3 = btree_create_node(&num[2]);
    t_btree* btree4 = btree_create_node(&num[3]);
    t_btree* btree5 = btree_create_node(&num[4]);
    t_btree* btree6 = btree_create_node(&num[5]);
    btree3->left = btree4;
    btree3->right = btree1;
    btree4->left = btree5;
    btree4->right = btree6;
    btree1->left = btree2;

    btree_apply_suffix(btree3, ft_putnbr_proxy);
    btree_delete_tree(btree3);
    return 0;
}