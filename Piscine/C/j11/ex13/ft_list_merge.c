#include "ft_list.h"

void ft_list_merge(t_list** begin_list1, t_list* begin_list2)
{
    if (!*begin_list1 || !begin_list2) return;
    t_list* begin_cpy = *begin_list1;
    while (begin_cpy->next)
        begin_cpy = begin_cpy->next;
    begin_cpy->next = begin_list2;
}