#pragma once
#include <string>

using str_t = std::string;

class ClapTrap
{
protected:
    unsigned int _maxHP{ 100 };
    unsigned int _maxEP{ 100 };
    unsigned int _hp{ _maxHP };
    unsigned int _ep{ _maxEP };
    unsigned int _lv{ 1 };
    str_t        _model{ "CL4P-TP" };
    str_t        _name{ "noname" };
    unsigned int _meleeDmg{ 30 };
    unsigned int _rangedDmg{ 20 };
    unsigned int _armor{ 5 };

public:
    ClapTrap();
    ClapTrap(str_t const&);
    ~ClapTrap();

    ClapTrap(ClapTrap const&);
    ClapTrap&    operator=(ClapTrap const&);

    str_t const& get_name() const;
    str_t const& get_model() const;

    unsigned int meleeAttack(str_t const&);
    unsigned int rangedAttack(str_t const&);
    void         takeDamage(unsigned int);
    void         beRepaired(unsigned int);
    void         reduceEnergy(unsigned int);
    void         say(str_t const&);
    void         status();
};