#include "ft_list.h"
#include <stdlib.h>

static t_list* ft_get_maxParent(t_list* list, int(*cmp)())
{
    t_list* parent = NULL;
    t_list* max = list;
    while (list->next) {
        if (cmp(max->data, list->next->data) < 0) {
            parent = list;
            max = parent->next;
        }
        list = list->next;
    }
    return parent;
}

void ft_list_sort(t_list** begin_list, int(*cmp)())
{
    if (!*begin_list || !(*begin_list)->next) return;
    t_list* sorted_list = NULL;
    while (*begin_list) {
        t_list* max = *begin_list;                      // Suppose max node is the first in the list
        t_list* parent = ft_get_maxParent(max, cmp);    // Compare with other nodes and return max node's parent
        if (parent) {                                   // Remove max node from the current list
            max = parent->next;
            parent->next = parent->next->next;
        }
        else                                            // The first node was the max node, move to the next
            *begin_list = (*begin_list)->next;
        max->next = sorted_list;                        // Push max node to the sorted list
        sorted_list = max;
    }
    *begin_list = sorted_list;
}