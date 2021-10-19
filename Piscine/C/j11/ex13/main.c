#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);
void ft_putstr(char const*);

int main()
{
    t_list* list1 = NULL;
    int a = 1, b = 2, c = 3;
    ft_list_push_front(&list1, &a);
    ft_list_push_front(&list1, &b);
    ft_list_push_front(&list1, &c);

    t_list* list2 = NULL;
    int d = 99, e = 100, f = 101;
    ft_list_push_front(&list2, &d);
    ft_list_push_front(&list2, &e);
    ft_list_push_front(&list2, &f);

    ft_list_merge(&list1, list2);
    while (list1) {
        ft_putnbr(*(int*)(list1->data)); ft_putstr(" ");
        t_list* toDelete = list1;
        list1 = list1->next;
        free(toDelete);
    }
    return 0;
}