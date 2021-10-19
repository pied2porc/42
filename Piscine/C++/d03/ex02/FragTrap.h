#pragma once
#include "ClapTrap.h"
#include <string>

using str_t = std::string;

class FragTrap : public virtual ClapTrap
{
public:
    FragTrap();
    FragTrap(str_t const&);
    ~FragTrap();
    
    FragTrap(FragTrap const&);
    FragTrap& operator=(FragTrap const&);

    unsigned int meleeAttack(str_t const&);
    unsigned int rangedAttack(str_t const&);

    unsigned int vaulthunter_dot_exe(str_t const&);

    unsigned int clapInTheBox(str_t const&);
    unsigned int laserInferno(str_t const&);
    unsigned int minionTrap(str_t const&);
    unsigned int meatUnicycle(str_t const&);
    unsigned int funzerker(str_t const&);
};