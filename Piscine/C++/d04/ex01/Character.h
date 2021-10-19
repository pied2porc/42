#pragma once
#include "AWeapon.h"
#include "Enemy.h"
#include <iostream>
#include <string>

using str_t = std::string;

class Character
{
private:
    str_t    _name{ "???" };
    int      _ap{ 40 };
    AWeapon* _weapon{ nullptr };

public:
    Character();
    Character(str_t const&);
    ~Character();

    Character(Character const&);
    Character& operator=(Character const&);

    str_t const& getName() const;
    int          getAP() const;
    AWeapon*     getWeapon() const;

    void equip(AWeapon*);
    void attack(Enemy**);
    void recoverAP();
};

std::ostream& operator<<(std::ostream&, Character const&);