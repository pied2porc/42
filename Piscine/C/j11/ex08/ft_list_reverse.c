#include "ft_list.h"

void ft_list_reverse(t_list** begin_list)
{
    t_list* rev_list = 0;

    while (*begin_list) {
        t_list* next = (*begin_list)->next;
        (*begin_list)->next = rev_list;
        rev_list = *begin_list;
        *begin_list = next;
    }
    *begin_list = rev_list;
}