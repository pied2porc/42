#pragma once
#include "ClapTrap.h"
#include <string>

using str_t = std::string;

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(str_t const&);
    ~ScavTrap();

    ScavTrap(ScavTrap const&);
    ScavTrap& operator=(ScavTrap const&);

    unsigned int meleeAttack(str_t const&);
    unsigned int rangedAttack(str_t const&);
    void         challengeNewcomer(str_t const&);
};