#pragma once

typedef struct s_op {
    char const* op;
    int (*f)(int, int);
} t_op;

int ft_add(int, int);
int ft_sub(int, int);
int ft_mul(int, int);
int ft_div(int, int);
int ft_mod(int, int);
int do_op(int, int, char const*);

int  ft_atoi(char const*);
void ft_putnbr(int);
void ft_putstr(char const*);