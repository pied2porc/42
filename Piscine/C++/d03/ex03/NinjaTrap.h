#pragma once
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <string>

using str_t = std::string;

class NinjaTrap : public virtual ClapTrap
{
public:
    NinjaTrap();
    NinjaTrap(str_t const&);
    ~NinjaTrap();

    NinjaTrap(NinjaTrap const&);
    NinjaTrap& operator=(NinjaTrap const&);

    unsigned int meleeAttack(str_t const&);
    unsigned int rangedAttack(str_t const&);

    void ninjaShoebox(ClapTrap const&);
    void ninjaShoebox(FragTrap const&);
    void ninjaShoebox(ScavTrap const&);
    void ninjaShoebox(NinjaTrap const&);
};