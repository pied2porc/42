#include "ft_btree_rb.h"

t_rb_node* rb_minimum(t_rb_node* node)
{
    while (node->left->data)
        node = node->left;
    return node;
}

t_rb_node* rb_maximum(t_rb_node* node)
{
    while (node->right->data)
        node = node->right;
    return node;
}

/* Return the smallest elem bigger than node */
t_rb_node* rb_successor(t_rb_node* node)
{
    // Search down for the leftmost elem in the right subtree of the node
    if (node->right->data)
        return rb_minimum(node->right);
    // Search up the tree for the lowest parent on the right of the subtree
    // of this node
    t_rb_node* ancestor = node->parent;
    while (ancestor->data && node == ancestor->right) {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

/* Return the largest elem smaller than node */
t_rb_node* rb_predecessor(t_rb_node* node)
{
    // Search down for the rightmost elem in the left subtree of the node
    if (node->left->data)
        return rb_maximum(node->left);
    // Search up the tree for the lowest parent on the left of the subtree
    // of this node
    t_rb_node* ancestor = node->parent;
    while (ancestor->data && node == ancestor->left) {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

t_rb_node* rb_search(t_rb_node* root, void* data,
    int (*cmpf)(void*, void*))
{
    if (!root || !cmpf(data, root->data))
        return root;
    else if (cmpf(data, root->data) < 0)
        return rb_search(root->left, data, cmpf);
    else
        return rb_search(root->right, data, cmpf);
}