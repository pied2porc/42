#include "ft_btree_rb.h"
#include <io.h>

void rb_apply_at_level(t_rb_node* root, int level, int isFirstElem,
    void (*applyf)(void* data, int level, int isFirstElem))
{
    if (!root->left && !root->right) return;
    if (level == 1)
        applyf(root, level, isFirstElem);
    else if (level > 1) {
        rb_apply_at_level(root->left, level - 1, 0, applyf);
        rb_apply_at_level(root->right, level - 1, 0, applyf);
    }
}

void rb_apply_by_level(t_rb_node* root,
    void (*applyf)(void* data, int level, int isFirstElem))
{
    int height = rb_level_count(root);
    int level = 0;
    while (++level <= height) {
        applyf(root, level, 1);
        rb_apply_at_level(root, level, 0, applyf);
        _write(1, "\n", 1);
    }
}