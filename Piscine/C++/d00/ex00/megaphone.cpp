#include <iostream>
#include <string>

void shout(std::string s)
{
    for (auto c : s) {
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        std::cout << c;
    }
}

int main(int ac, char* av[])
{
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    int i{ 0 };
    while (++i < ac)
        shout(av[i]);

    return 0;
}