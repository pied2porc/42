#include "PowerFist.h"
#include <iostream>

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {};
PowerFist::~PowerFist() { std::cout << _name << " destroyed\n"; }
PowerFist::PowerFist(PowerFist const& src) : AWeapon(src) {}
PowerFist& PowerFist::operator=(PowerFist const& rhs)
{
    // Gracefully handle self assignment
    AWeapon::operator=(rhs);
    return *this;
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *\n";
}