#pragma once
#include <string>

using str_t = std::string;

class Brain
{
    str_t m_address;

public:
    Brain();

    const str_t& identify() const;
};