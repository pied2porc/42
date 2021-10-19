#include "ft_list.h"

void ft_list_push_front(t_list** begin_list, const void* data)
{
    t_list* list = *begin_list;
    *begin_list = ft_create_elem(data);
    (*begin_list)->next = list;
}