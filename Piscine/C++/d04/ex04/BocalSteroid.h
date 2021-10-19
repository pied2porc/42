#pragma once
#include "DeepCoreMiner.h"
#include "IAsteroid.h"
#include "StripMiner.h"

class BocalSteroid : public IAsteroid
{
private:
    str_t _name{ "BocalSteroid" };

public:
    BocalSteroid();
    ~BocalSteroid();
    BocalSteroid(BocalSteroid const&);
    BocalSteroid& operator=(BocalSteroid const&);

    str_t getName() const;

    str_t beMined(DeepCoreMiner*) const;
    str_t beMined(StripMiner*) const;
};