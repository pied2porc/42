#include "StripMiner.h"
#include <iostream>

StripMiner::StripMiner() {}
StripMiner::~StripMiner() {}
StripMiner::StripMiner(StripMiner const& src) { *this = src; }
StripMiner& StripMiner::operator=(StripMiner const&) { return *this; }

void StripMiner::mine(IAsteroid* target)
{
    std::cout << "* strip mining ... got "<< target->beMined(this) << " ! *\n";
}