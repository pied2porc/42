#include "ft_btree.h"
#include <stdlib.h>

void ft_putstr(char const*);

int main()
{
    t_btree* btree = btree_create_node((char*)("root"));
    ft_putstr((char*)(btree->item));
    free(btree);
    return 0;
}