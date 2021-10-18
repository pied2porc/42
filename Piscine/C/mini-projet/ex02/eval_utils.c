#include "ft.h"
#include "stack.h"
#include "tokenize.h"
#include <stdlib.h>

void cleanup_n_die(char const* msg, t_token** stack1, t_token** stack2) {
    ft_putstr(msg);
    deleteStack(stack1);
    deleteStack(stack2);
    exit(EXIT_FAILURE);
}

int contains(char const* s, char c) {
    while (*s && *s != c) ++s;
    return !*s ? 0 : 1;
}

int do_op(char op, int lhs, int rhs)
{
    switch (op) {
    case '+': return lhs + rhs;
    case '-': return lhs - rhs;
    case '*': return lhs * rhs;
    case '/': return lhs / rhs;
    case '%': return lhs % rhs;
    default: return 0;
    }
}

int getSign(char** expr)
{
    int sign = 1;
    while (**expr == '+' || **expr == '-' || **expr == ' ') {
        if (**expr == '-') sign *= -1;
        ++(*expr);
    }
    return sign;
}

int getPrecedence(char op)
{
    switch (op){
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 2;
    default : return 0;
    }
}
