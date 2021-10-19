#include "BocalSteroid.h"
#include "DeepCoreMiner.h"
#include "StripMiner.h"

BocalSteroid::BocalSteroid() {}
BocalSteroid::~BocalSteroid() {}
BocalSteroid::BocalSteroid(BocalSteroid const& src) { *this = src; }
BocalSteroid& BocalSteroid::operator=(BocalSteroid const&) { return *this; }

str_t BocalSteroid::getName() const { return _name; }

str_t BocalSteroid::beMined(StripMiner*) const { return "Krpite"; }
str_t BocalSteroid::beMined(DeepCoreMiner*) const { return "Zazium"; }