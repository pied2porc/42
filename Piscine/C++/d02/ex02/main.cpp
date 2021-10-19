#include "Fixed.h"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout.precision(8);
    std::cout << a + b << "\n";
    std::cout << a - b << "\n";

    std::cout << Fixed(3) * Fixed(9) << "\n";
    std::cout << Fixed(1) / Fixed(3) << "\n";
    std::cout << Fixed(2.1f) + Fixed(3.5f) << "\n";

    return 0;
}