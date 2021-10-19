#include "ft_list.h"

void ft_putnbr(int);

int main()
{
    t_list* list = 0;
    int a = 1, b = 2, c = 3;
    ft_list_push_front(&list, &a);
    ft_list_push_front(&list, &b);
    ft_list_push_front(&list, &c);
    ft_putnbr(*(int*)(ft_list_last(list)->data));
    return 0;
}