#include "TacticalMarine.h"
#include <iostream>

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle\n";
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh...\n";
}

TacticalMarine::
TacticalMarine(TacticalMarine const& src) { *this = src; }

TacticalMarine&
TacticalMarine::operator=(TacticalMarine const&)
{
    return *this;
}

/* Member Functions */
ISpaceMarine* TacticalMarine::clone() const
{
    return new TacticalMarine();
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!\n";
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *\n";
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *\n";
}