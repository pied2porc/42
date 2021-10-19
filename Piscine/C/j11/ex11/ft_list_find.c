#include "ft_list.h"

t_list* ft_list_find(t_list* begin_list, void const* data_ref, int(*cmp)())
{
    while (begin_list && cmp(begin_list->data, data_ref))
        begin_list = begin_list->next;
    return begin_list;
}