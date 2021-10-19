#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);

int main()
{
    int data = 42;

    t_list* list = ft_create_elem(&data);
    ft_putnbr(*(int*)(list->data));

    free(list);
    return 0;
}