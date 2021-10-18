#include "ft.h"
#include "parser.h"
#include <stdlib.h>

int parseFactor(char** expr)
{
    int sign = 1;
    while (**expr == '+' || **expr == '-' || **expr == ' ') {
        if (**expr == '-') sign *= -1;
        ++(*expr);
    }
    if (**expr == '(') {
        ++(*expr);
        int res = parseSum(expr);
        if (**expr != ')') {
            if (**expr == '(')
                ft_putstr("error: parseFactor(): missing operator\n");
            else if (!**expr)
                ft_putstr("error: parseFactor(): missing parenthesis\n");
            else
                ft_putstr("error: parseFactor(): invalid character\n");
            exit(1);
        }
        ++(*expr);
        while (**expr == ' ') ++(*expr);
        return sign * res;
    }
    if (**expr == '*' || **expr == '/' || **expr == '%' ||
        **expr == ')' || **expr == '\0') {
        ft_putstr("error: parseFactor(): missing operands\n");
        exit(1);
    }
    int term = ft_atoi(*expr);
    while (**expr >= '0' && **expr <= '9' || **expr == ' ') ++(*expr);
    return sign * term;
}

int parseProduct(char** expr)
{   
    int lhs = parseFactor(expr);
    while (**expr == '*' || **expr == '/' || **expr == '%') {
        char op = **expr; // save operator
        ++(*expr);
        int rhs = parseFactor(expr);
        if (op == '*')
            lhs *= rhs;
        else {
            if (!rhs) {
                ft_putstr("error: parseProduct(): division by zero\n");
                exit(1);
            }
            lhs = (op == '/' ? lhs / rhs : lhs % rhs);
        }
    }
    return lhs;
}

int parseSum(char** expr)
{
    int lhs = parseProduct(expr);
    while (**expr == '+' || **expr == '-') {
        int rhs = parseProduct(expr);
        lhs += rhs;
    }
    return lhs;
}