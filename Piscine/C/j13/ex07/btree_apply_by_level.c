#include "ft_btree.h"
#include <io.h>

void btree_apply_at_level(t_btree* root, int level, int isFirstElem,
    void (*applyf)(void* item, int level, int isFirstElem))
{
    if (!root) return;
    if (level == 1)
        applyf(root->item, level, isFirstElem);
    else if (level > 1) {
        btree_apply_at_level(root->left, level - 1, 0, applyf);
        btree_apply_at_level(root->right, level - 1, 0, applyf);
    }
}

void btree_apply_by_level(t_btree* root,
    void (*applyf)(void* item, int level, int isFirstElem))
{
    int height = btree_level_count(root);
    int level = 0;
    while (++level <= height) {
        applyf(root->item, level, 1);
        btree_apply_at_level(root, level, 0, applyf);
        _write(1, "\n", 1);
    }
}