#include "conversion.h"

int main(int ac, char* av[])
{
    if (ac != 2) {
        std::cout << "usage: convert <number>\n";
        return EXIT_FAILURE;
    }
    Scalar scalar{ av[1] };
    std::cout << scalar;

    return EXIT_SUCCESS;
}