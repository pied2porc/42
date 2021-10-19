#include "Enemy.h"
#include <iostream>

/* Constructors & Destructors */
Enemy::Enemy() {}

Enemy::Enemy(int hp, str_t const& type) :
    _hp{ hp }, _type{ type } {}

Enemy::~Enemy() { std::cout << "Enemy destroyed\n"; }

/* Copy & Assignment */
Enemy::Enemy(Enemy const& src) { *this = src; }

Enemy& Enemy::operator=(Enemy const& rhs)
{
    // Gracefully handle self assignment
    _hp = rhs._hp;
    _type = rhs._type;
    return *this;
}

/* Getters & Setters */
str_t const& Enemy::getType() const { return _type; }
int          Enemy::getHP() const { return _hp; }

/* Member Functions */
void Enemy::takeDamage(int amount)
{
    if (_hp > 0) _hp -= amount;
}