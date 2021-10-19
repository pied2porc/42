#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list** begin_list, void const* data_ref, int(*cmp)())
{
    if (!*begin_list) return;
    t_list* begin_cpy = *begin_list;
    t_list* prev = NULL;
    while (begin_cpy)
        if (!cmp(begin_cpy->data, data_ref)) {
            if (!prev)
                *begin_list = begin_cpy->next;
            else
                prev->next = begin_cpy->next;
            t_list* toDelete = begin_cpy;
            begin_cpy = begin_cpy->next;
            free(toDelete);
        }
        else {
            prev = begin_cpy;
            begin_cpy = begin_cpy->next;
        }
}