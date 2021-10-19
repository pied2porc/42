#include "ft_list.h"
#include <stdlib.h>

void ft_putstr(char const*);
int  ft_strcmp(char const*, char const*);

int  ft_cmp(void const* a, void const* b)
{
    return ft_strcmp((char const*)(a), (char const*)(b));
}

int main()
{
    t_list* list1 = NULL;
    t_list* list2 = NULL;
    char const* a = "a", * b = "b", * c = "c";
    char const* d = "abc", * e = "123", * f = "xyz";
    ft_list_push_front(&list1, (void const*)a);
    ft_list_push_front(&list1, (void const*)b);
    ft_list_push_front(&list1, (void const*)c);
    ft_list_push_front(&list2, (void const*)d);
    ft_list_push_front(&list2, (void const*)e);
    ft_list_push_front(&list2, (void const*)f);
    ft_list_sort(&list1, ft_cmp);
    ft_list_sort(&list2, ft_cmp);

    ft_sorted_list_merge(&list1, list2, ft_cmp);

    while (list1) {
        ft_putstr((char const*)(list1->data)); ft_putstr(" ");
        t_list* toDelete = list1;
        list1 = list1->next;
        free(toDelete);
    }
    return 0;
}