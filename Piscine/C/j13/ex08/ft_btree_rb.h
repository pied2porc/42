#pragma once

typedef enum e_rb_color {
    RB_BLACK,
    RB_RED
} e_rb_color;

typedef struct s_rb_node {
    struct s_rb_node* parent;
    struct s_rb_node* left;
    struct s_rb_node* right;
    void*             data;
    enum e_rb_color   color;
}              t_rb_node;

/* create & delete */
t_rb_node*  rb_create_node(void*);
void        rb_delete_tree(t_rb_node*);

/* utils */
int         rb_level_count(t_rb_node*);
void        rb_print_node(void*, int, int);
void        rb_recolor(t_rb_node*, t_rb_node*, t_rb_node*);
void        rb_rotate(t_rb_node**, t_rb_node*, t_rb_node*,
                      void (*)(t_rb_node**, t_rb_node*),
                      void (*)(t_rb_node**, t_rb_node*));
void        rb_leftRotate(t_rb_node**, t_rb_node*);
void        rb_rightRotate(t_rb_node**, t_rb_node*);
void        rb_transplant(t_rb_node**, t_rb_node*, t_rb_node*);

/* insert */
void        rb_insert(t_rb_node**, void*, int (*)(void*, void*));
void        rb_insert_node(t_rb_node**, t_rb_node*, int (*)(void*, void*));
void        rb_insert_fixup(t_rb_node**, t_rb_node*);

/* remove */
void        rb_remove(t_rb_node**, void*, int (*)(void*, void*));
void        rb_remove_fixup(t_rb_node**, t_rb_node*);
void        rb_remove_fixup_left(t_rb_node**, t_rb_node**);
void        rb_remove_fixup_right(t_rb_node**, t_rb_node**);
void        rb_nodes_with_two_children(t_rb_node** root, t_rb_node* toRemove,
                                       t_rb_node** child, e_rb_color* originalColor);

/* search */
t_rb_node*  rb_search(t_rb_node*, void*,int (*)(void*, void*));
t_rb_node*  rb_minimum(t_rb_node*);
t_rb_node*  rb_maximum(t_rb_node*);
t_rb_node*  rb_successor(t_rb_node*);
t_rb_node*  rb_predecessor(t_rb_node*);

/* apply */
void        rb_apply_infix(t_rb_node*, void(*)(void*));
void        rb_apply_at_level(t_rb_node*, int, int, void (*)(void*, int, int));
void        rb_apply_by_level(t_rb_node*, void (*)(void*, int, int));