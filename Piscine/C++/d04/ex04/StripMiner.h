#pragma once
#include "IAsteroid.h"
#include "IMiningLaser.h"

class StripMiner : public IMiningLaser
{
public:
    StripMiner();
    ~StripMiner();
    StripMiner(StripMiner const&);
    StripMiner& operator=(StripMiner const&);
    
    void mine(IAsteroid*);
};