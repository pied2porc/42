#include "ft_perso.h"
#include <stdlib.h>

static int ft_get_age(char const** s)
{
    char const* end = *s;
    while (*end && *end != '|')
        ++end;

    int age = 0;
    while (**s && *s != end) {
        age *= 10;
        age += **s - '0';
        ++(*s);
    }
    if (*end)
        ++(*s);
    return age;
}

static char* ft_get_name(char const** s)
{
    char const* end = *s;
    while (*end && *end != ';')
        ++end;
    char* name = malloc((end - *s) + 1);
    if (!name) return 0;

    int i = -1;
    while (**s && *s != end) {
        name[++i] = **s;
        ++(*s);
    }
    name[++i] = '\0';
    if (*end)
        ++(*s);
    return name;
}

void ft_cleanup(t_perso** tab, t_perso** end)
{
    t_perso** ptr = tab;
    while (ptr < end) {
        free((void*)(*ptr)->name);
        free(*ptr);
        ++ptr;
    }
    free(tab);
}

t_perso** ft_decrypt(char const* str)
{
    int         size = 0;
    char const* begin = str;
    while (*str) {
        if (*str == '|')
            ++size;
        ++str;
    }
    str = begin;
    t_perso** tab = malloc(sizeof(*tab) * (size + 1));
    if (!tab) return 0;

    tab[size] = 0;
    size = -1;
    while (tab[++size]) {
        tab[size] = malloc(sizeof(t_perso));
        if (!tab[size]) {
            ft_cleanup(tab, tab + size);
            return NULL;
        }
        tab[size]->age = ft_get_age(&str);
        tab[size]->name = ft_get_name(&str);
    }
    return tab;
}