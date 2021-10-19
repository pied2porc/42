#pragma once
#include "AWeapon.h"
#include <string>

using str_t = std::string;

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();
    PlasmaRifle(PlasmaRifle const&);
    PlasmaRifle& operator=(PlasmaRifle const&);

    void attack() const;
};