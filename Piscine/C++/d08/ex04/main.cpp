#include "EvalExpr.h"
#include <iostream>

int main(int ac, char* av[])
{
    if (ac != 2) {
        std::cerr << "usage: evalexpr <expr>";
        return EXIT_FAILURE;
    }

    EvalExpr e;
    e.tokenize(av[1]);

    auto& tokens{ e.getTokens() };
    std::cout << "Tokens: ";
    for (auto t : tokens) std::cout << *t << ' ';

    try {
        e.postfix();
        auto& postfix{ e.getPostfix() };
        std::cout << "\nPostfix: ";
        for (auto t : postfix) std::cout << *t << ' ';
    }
    catch (std::runtime_error const& e) {
        std::cerr << "\nerror: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    try {
        e.eval();
        std::cout << "\nResult: " << e.getResult() << '\n';
    }
    catch (std::runtime_error const& e) {
        std::cerr << "\nerror: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}