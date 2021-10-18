#include "ft_btree_rb.h"
#include <io.h>

void ft_putnbr(int);

int rb_level_count(t_rb_node* root)
{
    if (!root->left && !root->right)
        return 0;
    int l = 1 + rb_level_count(root->left);
    int r = 1 + rb_level_count(root->right);
    return l > r ? l : r;
}

void rb_print_node(void* data, int level, int isFirstElem)
{
    if (isFirstElem) {
        _write(1, "Level ", 6);
        ft_putnbr(level);
        _write(1, ": ", 2);
    }
    else {
        t_rb_node* node = (t_rb_node*)(data);
        ft_putnbr(*(int*)(node->data));
        _write(1, node->color == RB_BLACK ? "b" : "R", 1);
        if (node->parent && node->parent->data) {
            _write(1, "(", 1);
            ft_putnbr(*(int*)(node->parent->data));
            _write(1, ")", 1);
        }
        _write(1, " ", 1);
    }
}

void rb_recolor(t_rb_node* parent, t_rb_node* uncle, t_rb_node* gparent)
{
    parent->color = RB_BLACK;
    uncle->color = RB_BLACK;
    gparent->color = RB_RED;
}

void rb_leftRotate(t_rb_node** root, t_rb_node* node)
{
    t_rb_node* child = node->right;
    node->right = child->left;
    if (child->left->data)
        child->left->parent = node;
    child->left = node;
    if (!node->parent->data)
        *root = child;
    else if (node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->parent = node->parent;
    node->parent = child;
}

void rb_rightRotate(t_rb_node** root, t_rb_node* node)
{
    t_rb_node* child = node->left;
    node->left = child->right;
    if (child->right->data)
        child->right->parent = node;
    child->right = node;
    if (!node->parent->data)
        *root = child;
    else if (node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->parent = node->parent;
    node->parent = child;
}

void rb_rotate(t_rb_node** root, t_rb_node* node, t_rb_node* parentSide,
    void (*first_rotf)(t_rb_node**, t_rb_node*),
    void (*second_rotf)(t_rb_node**, t_rb_node*))
{
    if (node == parentSide) {
        node = node->parent;
        first_rotf(root, node);
    }
    node->parent->color = RB_BLACK;
    node->parent->parent->color = RB_RED;
    second_rotf(root, node->parent->parent);
}

void rb_transplant(t_rb_node** root, t_rb_node* toRemove, t_rb_node* graft)
{
    if (!toRemove->parent->data)
        *root = graft;
    else if (toRemove == toRemove->parent->left)
        toRemove->parent->left = graft;
    else
        toRemove->parent->right = graft;
    if (graft)
        graft->parent = toRemove->parent;
}