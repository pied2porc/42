#include "Base.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::srand(static_cast<int>(std::time(nullptr)));
    std::rand();

    Base* base{ generate() };
    identify_from_pointer(base);
    identify_from_reference(*base);

    delete base;
    return 0;
}