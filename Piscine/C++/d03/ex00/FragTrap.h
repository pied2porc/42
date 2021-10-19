#pragma once
#include <string>

using str_t = std::string;

class FragTrap
{
    unsigned int  _maxHP{ 100 };
    unsigned int  _maxEP{ 100 };
    unsigned int _hp{ _maxHP };
    unsigned int _ep{ _maxEP };
    unsigned int _lv{ 1 };
    str_t        _name{ "FR4G-TP" };
    unsigned int _meleeDmg{ 30 };
    unsigned int _rangedDmg{ 20 };
    unsigned int _armor{ 5 };

public:
    FragTrap();
    FragTrap(str_t const&);
    ~FragTrap();
    FragTrap(FragTrap const&);

    FragTrap&    operator=(FragTrap const&);

    str_t const& get_name() const;

    unsigned int rangedAttack(str_t const&);
    unsigned int meleeAttack(str_t const&);
    void         takeDamage(unsigned int);
    void         beRepaired(unsigned int);

    unsigned int vaulthunter_dot_exe(str_t const&);

    unsigned int clapInTheBox(str_t const&);
    unsigned int laserInferno(str_t const&);
    unsigned int minionTrap(str_t const&);
    unsigned int meatUnicycle(str_t const&);
    unsigned int funzerker(str_t const&);
};