#include "parser.h"
#include "Fixed.h"

void removeSpaces(char* str) {
    char* seek{ str };
    while (*seek) {
        if (*seek != ' ') {
            *str = *seek;
            ++str;
        }
        ++seek;
    }
    *str = 0;
}

Fixed eval_expr(char const* xpr)
{
    Fixed res = parseSum(&xpr);
    if (*xpr) {
        std::cout << "error: syntax error.\n";
        exit(EXIT_FAILURE);
    }
    return res;
}

int main(int ac, char* av[])
{
    if (ac != 2) {
        std::cout << "usage: eval_expr <expr>\n";
        return EXIT_FAILURE;
    }
    removeSpaces(av[1]);
    char const* xpr = av[1];
    std::cout << eval_expr(xpr) << "\n";

    return EXIT_SUCCESS;
}