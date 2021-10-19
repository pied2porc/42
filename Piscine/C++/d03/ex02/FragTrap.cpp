#include "FragTrap.h"
#include <iostream>

/* Constructors & Destructors */
FragTrap::FragTrap() {}

FragTrap::FragTrap(str_t const& name) : ClapTrap(name)
{
    _model = "FR4G-TP";
    _maxHP = 100;
    _maxEP = 100;
    _hp = _maxHP;
    _ep = _maxEP;
    _lv = 1;
    _meleeDmg = 30;
    _rangedDmg = 20;
    _armor = 5;
    say("Hello! I'm model " + _model);
    status();
}

FragTrap::~FragTrap()
{
    say("I'll die the way I lived: annoying!");
}

/* Copy & Assignment */
FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

/* Member Functions */
unsigned int FragTrap::meleeAttack(str_t const& target)
{
    say("Take that!");
    return ClapTrap::meleeAttack(target);
}

unsigned int FragTrap::rangedAttack(str_t const& target)
{
    say("Hot potato!");
    return ClapTrap::rangedAttack(target);
}

/* Random attack */
unsigned int FragTrap::vaulthunter_dot_exe(str_t const& target)
{
    reduceEnergy(25);
    say("Loading combat package!");

    using FragTrap_fn = unsigned int(FragTrap::*)(str_t const&);
    static FragTrap_fn const attacks[]{
        &FragTrap::clapInTheBox,
        &FragTrap::laserInferno,
        &FragTrap::minionTrap,
        &FragTrap::meatUnicycle,
        &FragTrap::funzerker
    };
    static int max_atk{ sizeof(attacks) / sizeof(*attacks) };
    static double constexpr fraction{ 1.0 / (RAND_MAX + 1.0) };
    int rnb{ static_cast<int>(std::rand() * fraction * max_atk) };
    return (this->*attacks[rnb])(target);
}

/* Attacks */
unsigned int FragTrap::clapInTheBox(str_t const& target)
{
    say("Oh darn, oh boy, oh crap, oh boy, oh darn.");
    return rangedAttack(target);
}

unsigned int FragTrap::laserInferno(str_t const& target)
{
    say("Everybody, dance time! "
        "Da-da-da-dun-daaa-da-da-da-dun-daaa!");
    return meleeAttack(target);
}

unsigned int FragTrap::minionTrap(str_t const& target)
{
    say("Ratattattattatta! Powpowpowpow! Powpowpowpow! "
        "Pew-pew, pew-pew-pewpew!");
    return rangedAttack(target);
}

unsigned int FragTrap::meatUnicycle(str_t const& target)
{
    say("It's the only way to stop the voices!");
    return meleeAttack(target);
}

unsigned int FragTrap::funzerker(str_t const& target)
{
    say("If I had veins, they'd be popping out right now!");
    return rangedAttack(target);
}