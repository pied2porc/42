#pragma once
#include "IAsteroid.h"
#include "IMiningLaser.h"
#include <iostream>

class DeepCoreMiner : public IMiningLaser
{
public:
    DeepCoreMiner();
    ~DeepCoreMiner();
    DeepCoreMiner(DeepCoreMiner const&);
    DeepCoreMiner& operator=(DeepCoreMiner const&);
    
    void mine(IAsteroid*);
};