#include "ft_list.h"
#include <stdlib.h>

void ft_putstr(char const*);
int  ft_strcmp(char const*, char const*);
int  ft_cmp(void const* a, void const* b) {
    return ft_strcmp((char const*)(a), (char const*)(b));
}

int main()
{
    t_list* list = NULL;
    char const* a = "123", * b = "abc", * c = "42", * d = "xyz";
    ft_list_push_front(&list, (void*)(a));
    ft_list_push_front(&list, (void*)(b));
    ft_list_push_front(&list, (void*)(c));
    ft_list_push_front(&list, (void*)(d));
    t_list* found = ft_list_find(list, "42", ft_cmp);
    if (found)
        ft_putstr((char*)(found->data));

    while (list) {
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}
