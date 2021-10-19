#include "AsteroBocal.h"
#include "DeepCoreMiner.h"
#include "StripMiner.h"

AsteroBocal::AsteroBocal() {}
AsteroBocal::~AsteroBocal() {}
AsteroBocal::AsteroBocal(AsteroBocal const& src) { *this = src; }
AsteroBocal& AsteroBocal::operator=(AsteroBocal const&) { return *this; }

str_t AsteroBocal::getName() const { return _name; }

str_t AsteroBocal::beMined(StripMiner*) const { return "Flavium"; }
str_t AsteroBocal::beMined(DeepCoreMiner*) const { return "Thorite"; }