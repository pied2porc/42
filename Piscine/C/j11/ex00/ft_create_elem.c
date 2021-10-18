#include "ft_list.h"
#include <stdlib.h>

t_list* ft_create_elem(void* data)
{
    t_list* list = malloc(sizeof(*list));
    if (!list) return NULL;

    list->next = NULL;
    list->data = (data);
    return list;
}