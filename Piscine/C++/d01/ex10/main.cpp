#include "Cato9tails.h"

int main(int ac, char* av[])
{
    Cato9tails  cat;

    if (ac == 1) {
        cat.cat();
        return 0;
    }
    for (int i{ 1 }; i < ac; ++i)
        cat.cat(av[i]);

    return 0;
}