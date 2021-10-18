#include "ft_list.h"
#include <stdlib.h>

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list* parent = NULL;
    t_list* cur_node = *begin_list;
    while (cur_node && cmp(data, cur_node->data) > 0) {
        parent = cur_node;
        cur_node = cur_node->next;
    }
    t_list* toInsert = ft_create_elem(data);
    toInsert->next = cur_node;
    if (parent)
        parent->next = toInsert;
    else
        *begin_list = toInsert;
}