#include "ft_btree_rb.h"
#include <stdlib.h>

void rb_remove_fixup_left(t_rb_node** root, t_rb_node** node)
{
    t_rb_node* sibling = (*node)->parent->right;
    if (sibling->color == RB_RED) {             // Case 1A
        sibling->color = RB_BLACK;
        (*node)->parent->color = RB_RED;
        rb_leftRotate(root, (*node)->parent);
        sibling = (*node)->parent->right;
    }
    if (sibling->left->color == RB_BLACK &&
        sibling->right->color == RB_BLACK) {    // Case 2A
        sibling->color = RB_RED;
        *node = (*node)->parent;
    }
    else {
        if (sibling->right->color == RB_BLACK) {// Case 3A
            sibling->left->color = RB_BLACK;
            sibling->color = RB_RED;
            rb_rightRotate(root, sibling);
            sibling = (*node)->parent->right;
        }
        sibling->color = (*node)->parent->color;// Case 4A
        (*node)->parent->color = RB_BLACK;
        sibling->right->color = RB_BLACK;
        rb_leftRotate(root, (*node)->parent);
        *node = *root;
    }
}

void rb_remove_fixup_right(t_rb_node** root, t_rb_node** node)
{
    t_rb_node* sibling = (*node)->parent->left;
    if (sibling->color == RB_RED) {             // Case 1B
        sibling->color = RB_BLACK;
        (*node)->parent->color = RB_RED;
        rb_rightRotate(root, (*node)->parent);
        sibling = (*node)->parent->left;
    }
    if (sibling->left->color == RB_BLACK &&
        sibling->right->color == RB_BLACK) {    // Case 2B
        sibling->color = RB_RED;
        *node = (*node)->parent;
    }
    else {
        if (sibling->left->color == RB_BLACK) { // Case 3B
            sibling->right->color = RB_BLACK;
            sibling->color = RB_RED;
            rb_leftRotate(root, sibling);
            sibling = (*node)->parent->left;
        }
        sibling->color = (*node)->parent->color;// Case 4B
        (*node)->parent->color = RB_BLACK;
        sibling->left->color = RB_BLACK;
        rb_rightRotate(root, (*node)->parent);
        *node = *root;
    }
}

void rb_remove_fixup(t_rb_node** root, t_rb_node* node)
{
    while (node != *root && node->color == RB_BLACK) {
        if (node == node->parent->left)
            rb_remove_fixup_left(root, &node);  // Left Cases
        else
            rb_remove_fixup_right(root, &node); // Right Cases
    }
    node->color = RB_BLACK;
}

void rb_nodes_with_two_children(t_rb_node** root, t_rb_node* toRemove,
                                t_rb_node** child, e_rb_color* originalColor)
{
    t_rb_node* predecessor = rb_maximum(toRemove->left);
    *originalColor = predecessor->color;
    *child = predecessor->left;
    if (predecessor->parent == toRemove)
        (*child)->parent = predecessor;
    else {
        rb_transplant(root, predecessor, predecessor->left);
        predecessor->left = toRemove->left;
        predecessor->left->parent = predecessor;
    }
    rb_transplant(root, toRemove, predecessor);
    predecessor->right = toRemove->right;
    predecessor->right->parent = predecessor;
    predecessor->color = toRemove->color;
}

void rb_remove(t_rb_node** root, void* data, int (*cmpf)(void*, void*))
{
    t_rb_node* toRemove = rb_search(*root, data, cmpf);
    e_rb_color originalColor = toRemove->color;
    t_rb_node* child = NULL;

    // Nodes with only one child or no child
    if (!toRemove->left->data) {
        child = toRemove->right;
        rb_transplant(root, toRemove, toRemove->right);
    }
    else if (!toRemove->right->data) {
        child = toRemove->left;
        rb_transplant(root, toRemove, toRemove->left);
    }
    // Nodes with two children
    else
        rb_nodes_with_two_children(root, toRemove, &child, &originalColor);
    free(toRemove);
    toRemove = NULL;
    if (originalColor == RB_BLACK)
        rb_remove_fixup(root, child);
}