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
    t_list* list = NULL;
    char const* a = "a", * b = "b", * c = "c";
    char const* d = "abc", * e = "123", * f = "xyz";
    ft_list_push_front(&list, (void const*)a);
    ft_list_push_front(&list, (void const*)b);
    ft_list_push_front(&list, (void const*)c);
    ft_list_push_front(&list, (void const*)d);
    ft_list_push_front(&list, (void const*)e);
    ft_list_push_front(&list, (void const*)f);
    ft_list_sort(&list, ft_cmp);

    ft_sorted_list_insert(&list, "zzz", ft_cmp);
    ft_sorted_list_insert(&list, "aaa", ft_cmp);
    ft_sorted_list_insert(&list, "42", ft_cmp);
    ft_sorted_list_insert(&list, "1", ft_cmp);

    while (list) {
        ft_putstr((char const*)(list->data)); ft_putstr(" ");
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}