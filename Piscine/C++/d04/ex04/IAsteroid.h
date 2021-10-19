#pragma once
#include <string>

using str_t = std::string;

class DeepCoreMiner;
class StripMiner;

class IAsteroid
{
public:
    virtual ~IAsteroid() {}

    virtual str_t getName() const = 0;

    virtual str_t beMined(DeepCoreMiner*) const = 0;
    virtual str_t beMined(StripMiner*) const = 0;
};