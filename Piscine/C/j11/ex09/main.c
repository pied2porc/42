#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);
void ft_putstr(char const*);

void ft_print_int_data(void* data)
{
    ft_putnbr(*(int*)(data));
    ft_putstr("\n");
}

int main()
{
    t_list* list = NULL;
    int a = 1, b = 2, c = 3;
    ft_list_push_front(&list, &a);
    ft_list_push_front(&list, &b);
    ft_list_push_front(&list, &c);
    ft_list_foreach(list, ft_print_int_data);

    while (list) {
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}