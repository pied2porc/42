#include "Base.h"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <random>

Base::~Base() {}

Base* generate(void)
{
    int n{ std::rand() % 3 };
    switch (n) {
    case 0: return new A;
    case 1: return new B;
    case 2: return new C;
    default: return nullptr;
    }
}

void  identify_from_pointer(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void  identify_from_reference(Base& r)
{
    try {
        dynamic_cast<A&>(r);
        std::cout << "A\n";
        return;
    }
    catch (std::bad_cast&) {}
    try {
        dynamic_cast<B&>(r);
        std::cout << "B\n";
        return;
    }
    catch (std::bad_cast&) {}
    try {
        dynamic_cast<C&>(r);
        std::cout << "C\n";
        return;
    }
    catch (std::bad_cast&) {}
}