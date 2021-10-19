#pragma once
#include <string>

using str_t = std::string;

class Weapon
{
    str_t   m_type;

public:
    Weapon(str_t const&);

    str_t const& getType() const;
    void         setType(str_t const&);
};