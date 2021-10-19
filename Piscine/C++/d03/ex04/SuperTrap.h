#pragma once
#include "FragTrap.h"
#include "NinjaTrap.h"
#include <string>

using str_t = std::string;

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
    SuperTrap();
    SuperTrap(str_t const&);
    ~SuperTrap();

    SuperTrap(SuperTrap const&);
    SuperTrap& operator=(SuperTrap const&);

    unsigned int meleeAttack(str_t const&);
    unsigned int rangedAttack(str_t const&);
};