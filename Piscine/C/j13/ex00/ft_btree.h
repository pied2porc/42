#pragma once

typedef struct  s_btree {
    struct s_btree* left;
    struct s_btree* right;
    void*           item;
}               t_btree;

t_btree* btree_create_node(void*);
void     btree_delete_tree(t_btree*);
void     btree_apply_prefix(t_btree*, void(*)(void*));
void     btree_apply_infix(t_btree*, void(*)(void*));
void     btree_apply_suffix(t_btree*, void(*)(void*));
void     btree_insert_data(t_btree**, void*, int(*)(void*, void*));
void*    btree_search_item(t_btree*, void*, int(*)(void*, void*));
int      btree_level_count(t_btree*);
void     btree_apply_by_level(t_btree*, void (*)(void*, int, int));