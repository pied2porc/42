#include "easyfind.h"
#include <array>
#include <iostream>
#include <string>

int main()
{
    int arr[]{ 1, 2, 3, 4, 5, 10, 22, 27, 42, 56, 64, 128 };
    for (auto e : arr)
        std::cout << e << " ";
    std::cout << "\n";

    size_t pos{ 0 };
    if ((pos = easyfind(arr, 42)) != std::string::npos)
        std::cout << "42 found at pos=" << pos << '\n';
    else
        std::cout << "42 not found.\n";

    if ((pos = easyfind(arr, 32)) != std::string::npos)
        std::cout << "32 found at pos=" << pos << '\n';
    else
        std::cout << "32 not found.\n";

    std::cout << "\n";
    std::string s{ "0123456789abcdefghijklmnopqrstuvwxz\n" };
    std::cout << s;

    if ((pos = easyfind(s, 97)) != std::string::npos)
        std::cout << "97 found at pos=" << pos << '\n';
    else
        std::cout << "97 not found\n";

    if ((pos = easyfind(s, 32)) != std::string::npos)
        std::cout << "32 found at pos=" << pos << '\n';
    else
        std::cout << "32 not found\n";

    return 0;
}