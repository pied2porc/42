#include "parser.h"
#include "Fixed.h"

int parseSign(char const** xpr)
{
    int sign = 1;
    while (**xpr == '+' || **xpr == '-') {
        if (**xpr == '-')
            sign *= -1;
        ++(*xpr);
    }
    return sign;
}

Fixed parseFactor(char const** xpr)
{
    Fixed term{ parseSign(xpr) };
    if (**xpr == '(') {
        ++(*xpr);
        term = term * parseSum(xpr);
        if (**xpr != ')') {
            std::cout << "error: syntax error.\n";
            exit(EXIT_FAILURE);
        }
        ++(*xpr);
        return term;
    }
    term = term * std::atof(*xpr);
    while (isdigit(**xpr) || **xpr == '.') ++(*xpr);
    return term;
}

Fixed parseProduct(char const** xpr)
{
    Fixed lhs{ parseFactor(xpr) };
    while (**xpr == '*' || **xpr == '/') {
        char op = **xpr;
        ++(*xpr);
        Fixed rhs = parseFactor(xpr);
        if (op == '*')
            lhs = lhs * rhs;
        else {
            if (rhs == 0) {
                std::cout << "error: divide by zero.\n";
                exit(EXIT_FAILURE);
            }
            lhs = lhs / rhs;
        }
    }
    return lhs;
}

Fixed parseSum(char const** xpr)
{
    Fixed lhs{ parseProduct(xpr) };
    while (**xpr == '+' || **xpr == '-') {
        Fixed rhs = parseProduct(xpr);
        lhs = lhs + rhs;
    }
    return lhs;
}