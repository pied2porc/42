#pragma once
#include "Enemy.h"

class SuperMutant : public Enemy
{
public:
    SuperMutant();
    ~SuperMutant();
    SuperMutant(SuperMutant const&);
    SuperMutant& operator=(SuperMutant const&);

    void takeDamage(int);
};