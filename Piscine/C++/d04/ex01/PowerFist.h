#pragma once
#include "AWeapon.h"
#include <string>

using str_t = std::string;

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();
    PowerFist(PowerFist const&);
    PowerFist& operator=(PowerFist const&);

    void attack() const;
};