#pragma once
#include <string>

using str_t = std::string;

class AWeapon
{
protected:
    str_t   _name{ "???" };
    int     _dmg{ 0 };
    int     _ap{ 0 };

public:
    AWeapon();
    AWeapon(str_t const&, int, int);
    virtual ~AWeapon();
    
    AWeapon(AWeapon const&);
    AWeapon& operator=(AWeapon const&);

    str_t const& getName() const;
    int          getAPCost() const;
    int          getDamage() const;

    virtual void attack() const = 0;
};