#include "ft_list.h"

void ft_list_push_back(t_list** begin_list, void* data)
{
    if (!*begin_list) {
        *begin_list = ft_create_elem(data);
        return;
    }
    t_list* ptr = *begin_list;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = ft_create_elem(data);
}