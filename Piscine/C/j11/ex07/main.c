#include "ft_list.h"
#include <stdlib.h>

void ft_putnbr(int);
void ft_list_clear(t_list**);

int main()
{
    t_list* list = malloc(sizeof(*list));
    t_list* second = malloc(sizeof(*second));
    t_list* third = malloc(sizeof(*third));
    t_list* fourth = malloc(sizeof(*fourth));
    t_list* fifth = malloc(sizeof(*fifth));
    list->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    list->data = &a;
    second->data = &b;
    third->data = &c;
    fourth->data = &d;
    fifth->data = &e;

    for (int i = 0; i < 10; ++i) {
        t_list* node = ft_list_at(list, i);
        if (node)
            ft_putnbr(*(int*)(node->data));
    }
    ft_list_clear(&list);
    return 0;
}