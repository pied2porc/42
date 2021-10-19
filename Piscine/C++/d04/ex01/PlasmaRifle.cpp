#include "PlasmaRifle.h"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {};
PlasmaRifle::~PlasmaRifle() { std::cout << _name << " destroyed\n"; }
PlasmaRifle::PlasmaRifle(PlasmaRifle const& src) : AWeapon(src) {}
PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const& rhs)
{
    // Gracefully handle self assignment
    AWeapon::operator=(rhs);
    return *this;
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *\n";
}