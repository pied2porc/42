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
    char const* a = "42", * b = "abc", * c = "42", * d = "xyz", * e = "42";
    ft_list_push_front(&list, (void*)(a));
    ft_list_push_front(&list, (void*)(b));
    ft_list_push_front(&list, (void*)(c));
    ft_list_push_front(&list, (void*)(d));
    ft_list_push_front(&list, (void*)(e));
    ft_list_remove_if(&list, "42", ft_cmp);

    while (list) {
        ft_putstr((char*)(list->data)); ft_putstr("<");
        t_list* toDelete = list;
        list = list->next;
        free(toDelete);
    }
    return 0;
}
