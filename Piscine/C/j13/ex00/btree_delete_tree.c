#include "ft_btree.h"
#include <stdlib.h>

void btree_delete_tree(t_btree* tree)
{
    if (!tree) return;
    btree_delete_tree(tree->left);
    btree_delete_tree(tree->right);
    free(tree);
}