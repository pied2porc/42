#pragma once
#include "DeepCoreMiner.h"
#include "IAsteroid.h"
#include "StripMiner.h"

class AsteroBocal : public IAsteroid
{
private:
    str_t _name{ "AsteroBocal" };

public:
    AsteroBocal();
    ~AsteroBocal();
    AsteroBocal(AsteroBocal const&);
    AsteroBocal& operator=(AsteroBocal const&);

    str_t getName() const;

    str_t beMined(DeepCoreMiner*) const;
    str_t beMined(StripMiner*) const;
};