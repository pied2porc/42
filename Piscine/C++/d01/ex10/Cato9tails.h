#pragma once
#include <string>

using str_t = std::string;

class Cato9tails
{
private:
    str_t   m_fname{ "-" };

    void    catFromConsole();
    void    catFromFile();

public:
    void    cat(str_t const& = "-");
};