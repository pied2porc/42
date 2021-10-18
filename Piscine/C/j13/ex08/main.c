#include "ft_btree_rb.h"
#include <stdlib.h>

int ft_nbrcmp(void* n1, void* n2) {
    return *(int*)(n1) - *(int*)(n2);
}

int main()
{
    int num[] = { 7, 6, 5, 4, 3, 2, 1 };
    //int num[] = { 7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13 };
    //int num[] = { 10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70 };
    //int num[] = { 3, 7, 10, 12, 14, 15, 16, 17, 19, 20, 21, 23, 26, 28, 30, 35, 38, 39, 41, 47 };
    //int num[] = { 26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3 };

    int size = sizeof(num) / sizeof(*num);
    t_rb_node* rb = NULL;
  
    int i = -1;
    while (++i < size)
        rb_insert(&rb, &num[i], ft_nbrcmp);

    rb_apply_by_level(rb, rb_print_node);
    rb_delete_tree(rb);
    return 0;
}