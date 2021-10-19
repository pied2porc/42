#include "Enemy.h"
#include "SuperMutant.h"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::~SuperMutant() { std::cout << "Aaargh ...\n"; }

SuperMutant::SuperMutant(SuperMutant const& src) : Enemy(src) {}

SuperMutant& SuperMutant::operator=(SuperMutant const& rhs)
{
    // Gracefully handle self assignment
    Enemy::operator=(rhs);
    return *this;
}

void SuperMutant::takeDamage(int amount)
{
    Enemy::takeDamage(amount - 3);
}