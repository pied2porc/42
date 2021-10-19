#pragma once
#include "Enemy.h"

class RadScorpion : public Enemy
{
public:
    RadScorpion();
    ~RadScorpion();
    RadScorpion(RadScorpion const&);
    RadScorpion& operator=(RadScorpion const&);

    void takeDamage(int);
};