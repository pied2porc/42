#include "ft_list.h"

t_list* ft_list_at(t_list* begin_list, unsigned int nbr)
{
    unsigned int pos = 0;
    while (begin_list && ++pos != nbr)
        begin_list = begin_list->next;
    return !begin_list ? 0 : begin_list;
}