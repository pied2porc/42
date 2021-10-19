#include "AMateria.h"
#include "Character.h"
#include <iostream>

Character::Character() {}

Character::~Character() { for (auto& i : _inventory) delete i; }

Character::Character(str_t const& name) : _name{ name } {}

Character::
Character(Character const& src) : _name{ src._name } { deepCopy(src); }

Character& Character::operator=(Character const& rhs)
{
    if (this != &rhs) {
        _name = rhs._name;
        deepCopy(rhs);
    }
    return *this;
}

void Character::deepCopy(Character const& src)
{
    int i{ -1 };
    for (auto& m : _inventory){
        delete m;
        m = src._inventory[++i] ? src._inventory[i]->clone() : nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, Character const& c)
{
    for (int i{ 0 }; i < c.getInvSize(); ++i) {
        if (auto m = c.getMateria(i))
            out << m->getType() << "(" << m->getXP() << ") ";
    }
    return out;
}

/* Getters & Setters */
str_t const& Character::getName() const { return _name; }
AMateria*    Character::getMateria(int idx) const { return _inventory[idx]; }
int          Character::getInvSize() const { return _invSize; }

/* Member Functions */
void Character::equip(AMateria* m)
{
    for (auto& i : _inventory)
        if (!i) {
            i = m->clone();
            return;
        }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < _invSize)
        _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < _invSize && _inventory[idx])
        _inventory[idx]->use(target);
}