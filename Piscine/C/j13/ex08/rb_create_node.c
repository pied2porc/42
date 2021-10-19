#include "ft_btree_rb.h"
#include <stdlib.h>

t_rb_node* rb_create_node(void* data)
{
    t_rb_node* rb = malloc(sizeof(*rb));
    if (!rb) return NULL;

    rb->parent = rb->left = rb->right = NULL;
    rb->data = data;
    rb->color = RB_RED;

    return rb;
}