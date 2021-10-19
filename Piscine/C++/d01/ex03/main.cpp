#include "ZombieHorde.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return (min +
        static_cast<int>((max - min + 1) * std::rand() * fraction));
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand(); // discard first number
    std::cout << "--------------------------------------------------\n";
    
    ZombieHorde zh{ 10 };
    zh.announce();

    return 0;
}