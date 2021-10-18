#include "ft_list.h"
#include <stdlib.h>

void ft_putstr(char const*);

int main()
{
    t_list* list = NULL;
    char const* a = "a", * b = "b", * c = "c";
    char const* d = "d", * e = "e", * f = "f";
    ft_list_push_back(&list, (void*)a);
    ft_list_push_back(&list, (void*)b);
    ft_list_push_back(&list, (void*)c);
    ft_list_push_back(&list, (void*)d);
    ft_list_push_back(&list, (void*)e);
    ft_list_push_back(&list, (void*)f);

    ft_list_reverse_fun(list);

    while (list) {
        ft_putstr((char*)(list->data)); ft_putstr(" ");
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}