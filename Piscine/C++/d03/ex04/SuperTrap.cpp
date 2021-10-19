#include "SuperTrap.h"
#include <iostream>

/* Constructors & Destructors */
SuperTrap::SuperTrap() {}

// This exercise could actually benefit from NOT using the keyword 'virtual'
// so that NinjaTrap wouldn't overwrite FragTrap's member variables' values.
// But it means each derived class would have their own base class instance.
SuperTrap::SuperTrap(str_t const& name) :
    ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    _model = "SUP3R-TP";
    _maxHP = 100;
    _maxEP = NinjaTrap::_ep;
    _hp = _maxHP;
    _ep = _maxEP;
    _meleeDmg = NinjaTrap::_meleeDmg;
    _rangedDmg = 20;
    _armor = 5;
    say("'sup! I'm " + _model);
    status();
}

SuperTrap::~SuperTrap()
{
    say("Boo-hoo! I'm not " + _model + "...");
}

/* Copy & Assignment */
SuperTrap::SuperTrap(SuperTrap const& src) :
    ClapTrap(src), FragTrap(src), NinjaTrap(src) {}

SuperTrap& SuperTrap::operator=(SuperTrap const& rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

/* Member Functions */
unsigned int SuperTrap::meleeAttack(str_t const& target)
{
    return NinjaTrap::meleeAttack(target);
}

unsigned int SuperTrap::rangedAttack(str_t const& target)
{
    return FragTrap::rangedAttack(target);
}