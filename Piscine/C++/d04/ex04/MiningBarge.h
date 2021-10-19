#pragma once
#include "IMiningLaser.h"
#include "IAsteroid.h"

class MiningBarge
{
private:
    IMiningLaser* _lasers[4]{ nullptr };

public:
    MiningBarge();
    ~MiningBarge();
    MiningBarge(MiningBarge const&) = delete;
    MiningBarge& operator=(MiningBarge const&) = delete;

    void equip(IMiningLaser*);
    void mine(IAsteroid*) const;
};