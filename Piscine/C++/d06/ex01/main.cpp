#include "serialize.h"
#include <iostream>

int main()
{
    void* s{ serialize() };
    Data* d{ deserialize(s) };

    std::cout << d->s1 << "\n";
    std::cout << d->n << "\n";
    std::cout << d->s2 << "\n";

    delete s;
    delete d;
    return 0;
}