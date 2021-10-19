#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);
void ft_putstr(char const*);

int main()
{
    t_list* list = NULL;
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    ft_list_push_back(&list, &a);
    ft_list_push_back(&list, &b);
    ft_list_push_back(&list, &c);
    ft_list_push_back(&list, &d);
    ft_list_push_back(&list, &e);

    ft_list_reverse(&list);
    while (list) {
        ft_putnbr(*(int*)(list->data)); ft_putstr(" ");
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}