#include "ft_list.h"

t_list* ft_list_push_params(int ac, char* av[])
{
    t_list* begin_list = 0;
    int     i = 0;
    while (++i < ac) {
        t_list* list = begin_list;
        begin_list = ft_create_elem(av[i]);
        begin_list->next = list;
    }
    return begin_list;
}