#include "Array.h"
#include <iostream>
#include <string>

int main()
{
    Array<int> a(5);
    for (size_t i{ 0 }; i < a.size(); ++i)
        a[i] = i + 1;

    std::cout << "a[]= ";
    for (size_t i{ 0 }; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";

    Array<int> b;
    std::cout << "b[]= ";
    for (size_t i{ 0 }; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    Array<int>c(a);
    b = a;
    a[0] = 42;
    std::cout << "a[0]= " << a[0] << "\n";

    std::cout << "b[]= ";
    for (size_t i{ 0 }; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << "(assignment)\n";

    std::cout << "c[]= ";
    for (size_t i{ 0 }; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << "(copy)\n";

    Array<std::string> d(4);
    d[0] = "tata"; d[1] = "titi"; d[2] = "toto"; d[3] = "tutu";
    std::cout << "d[]= ";
    for (size_t i{ 0 }; i < d.size(); ++i)
        std::cout << d[i] << " ";
    std::cout << "\n";

    try {
        std::cout << "d[5]= " << d[5] << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "\nerror: " << e.what() << "\n";
    }
  
    return 0;
}