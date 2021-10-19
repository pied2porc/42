#include "HumanB.h"
#include <iostream>

HumanB::HumanB(str_t const& name) : m_name{ name } {}

void HumanB::attack()
{
    std::cout << m_name << " attacks with his "
        << m_weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon) { m_weapon = &weapon; }