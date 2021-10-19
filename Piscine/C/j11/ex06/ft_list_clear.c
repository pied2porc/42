#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list** begin_list)
{
    t_list* ptr = *begin_list;
    while (ptr) {
        t_list* toDelete = ptr;
        ptr = ptr->next;
        free(toDelete);
    }
    *begin_list = NULL;
}