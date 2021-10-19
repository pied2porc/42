#include "ft_list.h"
#include <stdlib.h>

void ft_sorted_list_merge(t_list** begin_list1, t_list* begin_list2, int(*cmp)())
{
    t_list* cur_node = *begin_list1;
    t_list* parent = NULL;
    while (begin_list2) {
        while (cur_node && cmp(begin_list2->data, cur_node->data) > 0) {
            parent = cur_node;
            cur_node = cur_node->next;
        }
        t_list* toMerge = begin_list2;
        begin_list2 = begin_list2->next;
        toMerge->next = cur_node;
        if (parent)
            parent->next = toMerge;
        else
            *begin_list1 = toMerge;
    }
}