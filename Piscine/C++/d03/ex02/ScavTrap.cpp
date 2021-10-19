#include "ScavTrap.h"
#include <iostream>

/* Constructors & Destructors */
ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(str_t const& name) : ClapTrap(name)
{
    _model = "SC4V-TP";
    _maxHP = 100;
    _maxEP = 50;
    _hp = _maxHP;
    _ep = _maxEP;
    _lv = 1;
    _meleeDmg = 20;
    _rangedDmg = 15;
    _armor = 3;
    say("Hey! I'm model " + _model);
    status();
}

ScavTrap::~ScavTrap()
{
    say("The robot is dead, long live the robot!");
}

/* Copy & Assignment */
ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

/* Actions */
unsigned int ScavTrap::meleeAttack(str_t const& target)
{
    say("Heyyah!");
    return ClapTrap::meleeAttack(target);
}

unsigned int ScavTrap::rangedAttack(str_t const& target)
{
    say("Present for you!");
    return ClapTrap::rangedAttack(target);
}

void ScavTrap::challengeNewcomer(str_t const& target)
{
    reduceEnergy(25);
    say("Loading challenge package!");

    static str_t const challenges[]{
        " to take out the garbage!",
        " to go on a date with Kwame!",
        " to hold his breath for 42 secondes!",
        " to peel a banana with his feet!",
        " to eat his nose shit!"
    };
    static int max_atk{ sizeof(challenges) / sizeof(*challenges) };
    static double constexpr fraction{ 1.0 / (RAND_MAX + 1.0) };
    int rnb{ static_cast<int>(std::rand() * fraction * max_atk) };
    std::cout << "\t" << _model << " " << _name << " challenges "
        << target << challenges[rnb] << "\n";
}