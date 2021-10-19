#include "Enemy.h"
#include "RadScorpion.h"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion")
{
    std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion() { std::cout << "* SPROTCH *\n"; }

RadScorpion::RadScorpion(RadScorpion const& src) : Enemy(src) {}

RadScorpion& RadScorpion::operator=(RadScorpion const& rhs)
{
    // Gracefully handle self assignment
    Enemy::operator=(rhs);
    return *this;
}

void RadScorpion::takeDamage(int amount)
{
    Enemy::takeDamage(amount);
}