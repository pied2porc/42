#include "NinjaTrap.h"
#include <iostream>

/* Constructors & Destructors */
NinjaTrap::NinjaTrap() {}

NinjaTrap::NinjaTrap(str_t const& name) : ClapTrap(name)
{
    _model = "N1NJ4-TP";
    _maxHP = 60;
    _maxEP = 120;
    _hp = _maxHP;
    _ep = _maxEP;
    _lv = 1;
    _meleeDmg = 60;
    _rangedDmg = 5;
    _armor = 0;
    say("Nin nin! I'm model " + _model);
    status();
}

NinjaTrap::~NinjaTrap()
{
    say("Namu namu");
}

/* Copy & Assignment */
NinjaTrap::NinjaTrap(NinjaTrap const& src) : ClapTrap(src) {}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const& rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

/* Member Functions */
unsigned int NinjaTrap::meleeAttack(str_t const& target)
{
    say("Shoryuken!");
    return ClapTrap::meleeAttack(target);
}

unsigned int NinjaTrap::rangedAttack(str_t const& target)
{
    say("Hadoken!");
    return ClapTrap::rangedAttack(target);
}

/* Actions */
void NinjaTrap::ninjaShoebox(ClapTrap const& target)
{
    reduceEnergy(25);
    say("Loading assassin package");
    std::cout << "\t" << target.get_model() << " " << target.get_name()
              << "'s pants has been stolen\n";
}

void NinjaTrap::ninjaShoebox(FragTrap const& target)
{
    reduceEnergy(25);
    say("Loading assassin package");
    std::cout << "\t" << target.get_model() << " " << target.get_name()
              << "'s package has been stolen\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap const& target)
{
    reduceEnergy(25);
    say("Loading assassin package");
    std::cout << "\t" << target.get_model() << " " << target.get_name()
              << "'s datas has been stolen\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap const& target)
{
    reduceEnergy(25);
    say("Loading assassin package");
    std::cout << "\t" << target.get_model() << " " << target.get_name()
              << "'s bento box has been stolen\n";
}