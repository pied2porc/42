#include "Mindopen.h"
#include <filesystem>
#include <fstream>
#include <iostream>

int main(int ac, char* av[])
{
    if (ac == 1) {
        std::cout << "usage: mindopen <sourcefile>\n";
        return EXIT_FAILURE;
    }
    for (int i{ 1 }; i < ac; ++i) {
        std::ifstream ifs{ av[i] };
        if (!ifs) {
            std::cerr << "Cannot open " << av[i] << "\n";
            continue;
        }
        Mindopen bf;
        bf.queue(ifs);
        bf.execute();
    }
    return EXIT_SUCCESS;
}