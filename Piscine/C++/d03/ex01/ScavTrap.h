#pragma once
#include <string>

using str_t = std::string;

class ScavTrap
{
    unsigned int _maxHP{ 100 };
    unsigned int _maxEP{ 50 };
    unsigned int _hp{ _maxHP };
    unsigned int _ep{ _maxEP };
    unsigned int _lv{ 1 };
    str_t        _name{ "SC4V-TP" };
    unsigned int _meleeDmg{ 20 };
    unsigned int _rangedDmg{ 15 };
    unsigned int _armor{ 3 };

public:
    ScavTrap();
    ScavTrap(str_t const&);
    ~ScavTrap();
    ScavTrap(ScavTrap const&);

    ScavTrap&    operator=(ScavTrap const&);

    str_t const& get_name() const;

    unsigned int rangedAttack(str_t const&);
    unsigned int meleeAttack(str_t const&);
    void         takeDamage(unsigned int);
    void         beRepaired(unsigned int);

    void         challengeNewcomer(str_t const&);
};