#include "ft_btree.h"
#include <stdlib.h>

void* btree_search_item(t_btree* root, void* data_ref,
    int(*cmpf)(void*, void*))
{
    if (!root) return NULL;
    if (cmpf(data_ref, root->item) < 0)
        return btree_search_item(root->left, data_ref, cmpf);
    else if (cmpf(data_ref, root->item) > 0)
        return btree_search_item(root->right, data_ref, cmpf);
    return root->item;
}