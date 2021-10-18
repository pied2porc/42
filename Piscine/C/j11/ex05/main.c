#include "ft_list.h"
#include <stdlib.h>

void ft_putstr(char const*);

int main(int ac, char* av[])
{
    t_list* list = ft_list_push_params(ac, av);
    while (list) {
        ft_putstr((char*)(list->data)); ft_putstr(" ");
        t_list* tmp = list;
        list = list->next;
        free(tmp);
    }
    free(list);
    return 0;
}
