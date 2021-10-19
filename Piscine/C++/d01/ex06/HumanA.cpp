#include "HumanA.h"
#include <iostream>

HumanA::HumanA(str_t const& name, Weapon& weapon) :
    m_name{ name }, m_weapon{ weapon } {}

void HumanA::attack()
{
    std::cout << m_name << " attacks with his "
        << m_weapon.getType() << "\n";
}