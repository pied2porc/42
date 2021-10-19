#pragma once

typedef struct s_opp {
    char const* op;
    int (*f)(int, int);
} t_opp;

int ft_add(int, int);
int ft_sub(int, int);
int ft_mul(int, int);
int ft_div(int, int);
int ft_mod(int, int);
int ft_usage(int, int);
void do_op(int, int, char*);

int  ft_atoi(char const*);
void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_strcmp(char const*, char const*);