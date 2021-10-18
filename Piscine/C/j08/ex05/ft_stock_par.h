#pragma once

typedef struct s_stock_par {
    int    size_param;
    char*  str;
    char*  copy;
    char** tab;
} t_stock_par;

void         ft_putchar(char);
void         ft_putnbr(int);
void         ft_putstr(char const*);
int          ft_strlen(char const*);
char*        ft_strndup(char const*, int);
t_stock_par* ft_param_to_tab(int, char* []);
char**       ft_split_whitespaces(char const*);
void         ft_show_tab(t_stock_par* par);