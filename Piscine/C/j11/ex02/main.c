#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);
void ft_putstr(char const*);

int main()
{
    t_list* list = NULL;
    int a = 42;
    int b = 99;
    int c = 202;
    ft_list_push_front(&list, &a);
    ft_list_push_front(&list, &b);
    ft_list_push_front(&list, &c);
    while (list) {
        ft_putnbr(*(int*)(list->data)); ft_putstr(" ");
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}