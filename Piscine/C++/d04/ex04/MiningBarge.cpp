#include "MiningBarge.h"

MiningBarge::MiningBarge() {}
MiningBarge::~MiningBarge()
{
    for (auto &l : _lasers)
        delete l;
}

void MiningBarge::equip(IMiningLaser* laser)
{
    for (auto& l : _lasers)
        if (!l) {
            l = laser;
            return;
        }
}

void MiningBarge::mine(IAsteroid* a) const
{
    for (auto& l : _lasers) {
        if (l)
            l->mine(a);
    }
}