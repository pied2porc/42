
#include "AWeapon.h"
#include <iostream>

/* Constructors & Destructors */
AWeapon::AWeapon() {}

AWeapon::AWeapon(str_t const& name, int ap, int dmg) :
    _name{ name }, _ap{ ap }, _dmg{ dmg } {}

AWeapon::~AWeapon() { std::cout << "Weapon destroyed\n"; }

/* Copy & Assignment */
AWeapon::AWeapon(AWeapon const& src) { *this = src; }

AWeapon& AWeapon::operator=(AWeapon const& rhs)
{
    // Gracefully handle self assignment
    _name = rhs._name;
    _dmg = rhs._dmg;
    _ap = rhs._ap;
    return *this;
}

/* Getters & Setters */
str_t const& AWeapon::getName() const { return _name; }
int          AWeapon::getAPCost() const { return _ap; }
int          AWeapon::getDamage() const { return _dmg; }