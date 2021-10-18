#include "ft_list.h"
#include <stdlib.h>

int main()
{
    t_list* first = malloc(sizeof(*first));
    t_list* second = malloc(sizeof(*second));
    t_list* third = malloc(sizeof(*third));
    first->next = second;
    second->next = third;
    third->next = NULL;

    ft_list_clear(&first);
    return 0;
}