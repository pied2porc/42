#include "ft_btree_rb.h"
#include <stdlib.h>

void rb_insert_node(t_rb_node** root, t_rb_node* node,
                    int (*cmpf)(void*, void*))
{
    if (!*root) {
        *root = malloc(sizeof(**root));
        **root = (t_rb_node){ NULL, NULL, NULL, NULL, RB_BLACK };
    }
    if (!(*root)->left && !(*root)->right) {
        if (!node->parent)  // root's parent points to NIL
            node->parent = *root;
        node->left = node->right = *root;
        *root = node;
        return;
    }
    node->parent = *root;
    if (cmpf(node->data, (*root)->data) < 0)
        rb_insert_node(&(*root)->left, node, cmpf);
    else
        rb_insert_node(&(*root)->right, node, cmpf);
}

void rb_insert_fixup(t_rb_node** root, t_rb_node* node)
{
    while (node != *root && node->parent->color == RB_RED) {
        t_rb_node* p = node->parent;
        t_rb_node* gp = p->parent;

        if (p == gp->left) {            // Left Cases
            t_rb_node* u = gp->right;   // uncle is RED
            if (u->color == RB_RED) {
                rb_recolor(p, u, gp);
                node = gp;
            }
            else                        // uncle is BLACK or NIL
                rb_rotate(root, node, p->right,
                    rb_leftRotate, rb_rightRotate);
        }
        else {                          // Right Cases
            t_rb_node* u = gp->left;    // uncle is RED
            if (u->color == RB_RED) {
                rb_recolor(p, u, gp);
                node = gp;
            }
            else                        // uncle is BLACK or NIL
                rb_rotate(root, node, p->left,
                    rb_rightRotate, rb_leftRotate);
        }
    }
    (*root)->color = RB_BLACK;
}

void rb_insert(t_rb_node** root, void* data, int (*cmpf)(void*, void*))
{
    t_rb_node* node = rb_create_node(data);
    rb_insert_node(root, node, cmpf);
    rb_insert_fixup(root, node);
}