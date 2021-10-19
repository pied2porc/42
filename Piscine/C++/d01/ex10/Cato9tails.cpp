#define _CRT_SECURE_NO_WARNINGS
#include "Cato9tails.h"
#include <fstream>
#include <iostream>

void Cato9tails::catFromConsole()
{
    std::string input;
    while (std::getline(std::cin, input))
        std::cout << input << "\n";
}

void Cato9tails::catFromFile()
{
    errno = 0;
    std::ifstream ifs(m_fname);
    if (!ifs) {
        std::cerr << "cat: " << m_fname << ": "
            << std::strerror(errno) << "\n";
        return;
    }
    str_t input;
    while (!ifs.eof()) {
        std::getline(ifs, input);
        std::cout << input << "\n";
    }
}

void Cato9tails::cat(str_t const& fname)
{
    m_fname = fname;
    fname == "-" ? catFromConsole() : catFromFile();
}