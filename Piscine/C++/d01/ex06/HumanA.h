#pragma once
#include "Weapon.h"
#include <string>

using str_t = std::string;

class HumanA
{
    str_t   m_name;
    Weapon& m_weapon;

public:
    HumanA(str_t const&, Weapon&);

    void attack();
};