#include "DeepCoreMiner.h"
#include <iostream>

DeepCoreMiner::DeepCoreMiner() {}
DeepCoreMiner::~DeepCoreMiner() {}
DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const& src) { *this = src; }
DeepCoreMiner& DeepCoreMiner::operator=(DeepCoreMiner const&) { return *this; }

void DeepCoreMiner::mine(IAsteroid* target)
{
    std::cout << "* mining deep ... got "<< target->beMined(this) << " ! *\n";
}