#pragma once

typedef struct s_list {
    struct s_list* next;
    void*          data;
} t_list;

t_list* ft_create_elem(void const*);
void    ft_list_push_back(t_list**, void const*);
void    ft_list_push_front(t_list**, void const*);
int     ft_list_size(t_list*);
t_list* ft_list_last(t_list*);
t_list* ft_list_push_params(int, char* []);
void    ft_list_clear(t_list**);
t_list* ft_list_at(t_list*, unsigned int);
void    ft_list_reverse(t_list**);
void    ft_list_foreach(t_list*, void(*)(void*));
void    ft_list_foreach_if(t_list*, void(*)(void*), void const*, int(*)());
t_list* ft_list_find(t_list*, void const*, int(*)());
void    ft_list_remove_if(t_list**, void const*, int(*)());
void    ft_list_merge(t_list**, t_list*);
void    ft_list_sort(t_list**, int(*)());
void    ft_list_reverse_fun(t_list*);
void    ft_sorted_list_insert(t_list**, void const*, int(*)());
void    ft_sorted_list_merge(t_list**, t_list*, int(*)());