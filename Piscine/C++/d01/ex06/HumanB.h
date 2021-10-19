#pragma once
#include "Weapon.h"
#include <string>

using str_t = std::string;

class HumanB
{
    str_t   m_name;
    Weapon* m_weapon;

public:
    HumanB(str_t const&);

    void attack();
    void setWeapon(Weapon&);
};