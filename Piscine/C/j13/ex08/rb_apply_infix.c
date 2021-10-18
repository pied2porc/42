#include "ft_btree_rb.h"

void rb_apply_infix(t_rb_node* root, void(*applyf)(void*))
{
    if (!root->left && !root->right) return;
    rb_apply_infix(root->left, applyf);
    applyf(root->data);
    rb_apply_infix(root->right, applyf);
}