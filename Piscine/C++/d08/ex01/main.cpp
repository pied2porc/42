#include "Span.h"
#include <ctime>
#include <iostream>
#include <random>

namespace Rand {
    std::mt19937 gen{
        static_cast<std::mt19937::result_type>
        (std::time(nullptr)) };
}

int rng(int min, int max)
{
    std::uniform_int_distribution dist{ min, max };
    return dist(Rand::gen);
}

int main()
{

    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        sp.addNumber(42);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    std::cout << sp << '\n';

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span s(10'000);
    s.fillNumber(1000, 100'000);
    
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;

    return 0;
}