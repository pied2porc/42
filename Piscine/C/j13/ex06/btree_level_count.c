#include "ft_btree.h"

int btree_level_count(t_btree* root)
{
    if (!root)
        return 0;
    int l = 1 + btree_level_count(root->left);
    int r = 1 + btree_level_count(root->right);
    return l > r ? l : r;
}