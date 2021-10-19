#include "Character.h"

/* Constructors & Destructors */
Character::Character() {}

Character::Character(str_t const& name) : _name{ name } {}

Character::~Character() { std::cout << _name << " destroyed\n"; }

/* Copy & Assignment */
Character::Character(Character const& src) { *this = src; }
    
Character& Character::operator=(Character const& rhs)
{
    // Gracefully handle self assignment
    _name = rhs._name;
    _ap = rhs._ap;
    _weapon = rhs._weapon;
    return *this;
}

/* Operator Overloads */
std::ostream& operator<<(std::ostream& out, Character const& c)
{
    out << c.getName() << " has " << c.getAP() << " AP and ";
    if (c.getWeapon())
        out << "wields a " << c.getWeapon()->getName() << "\n";
    else
        out << "is unarmed\n";
    return out;
}

/* Getters & Setters */
str_t const& Character::getName() const { return _name; }
int          Character::getAP() const { return _ap; }
AWeapon*     Character::getWeapon() const { return _weapon; }

/* Member Functions */
void Character::equip(AWeapon* weapon) { _weapon = weapon; }

void Character::attack(Enemy** enemy)
{
    if (!*enemy) {
        std::cout << "Sadly, the enemy has already died.\n";
        return;
    }
    if (!_weapon)
        std::cout << _name << " needs a weapon\n";
    else if (_ap < _weapon->getAPCost())
        std::cout << _name << " is exhausted\n";
    else {
        std::cout << _name << " attacks " << (*enemy)->getType()
                  << " with a " << _weapon->getName() << "\n";
        _ap -= _weapon->getAPCost();
        _weapon->attack();
        (*enemy)->takeDamage(_weapon->getDamage());
        if ((*enemy)->getHP() <= 0) {
            delete *enemy;
            *enemy = nullptr;
        }
    }
}

void Character::recoverAP()
{
    static int constexpr maxAP{ 40 };
    int ap{ _ap <= maxAP - 10 ? 10 : maxAP - _ap };
    _ap += ap;
    std::cout << _name << " recovered " << ap << " AP\n";
}