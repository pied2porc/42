#include "ft_list.h"
#include <stdlib.h>

void ft_list_reverse_fun(t_list* begin_list)
{
    if (!begin_list || !begin_list->next) return;

    t_list* end_list = NULL;
    void* data = NULL;
    while (begin_list != end_list) {
        end_list = begin_list->next;
        while (end_list->next && end_list->next->data != data)
            end_list = end_list->next;
        data = begin_list->data;
        begin_list->data = end_list->data;
        end_list->data = data;
        begin_list = begin_list->next;
    }
}