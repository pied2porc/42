#include "ft_btree_rb.h"
#include <stdlib.h>

void rb_delete_tree(t_rb_node* rb)
{
    if (!rb->left && !rb->right)
        return;
    rb_delete_tree(rb->left);
    rb_delete_tree(rb->right);
    if (!rb->parent->parent) // delete NIL
        free(rb->parent);
    free(rb);
}