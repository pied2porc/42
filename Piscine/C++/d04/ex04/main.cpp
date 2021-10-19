#include "AsteroBocal.h"
#include "BocalSteroid.h"
#include "DeepCoreMiner.h"
#include "StripMiner.h"
#include "MiningBarge.h"
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    MiningBarge mb;
    IMiningLaser* dcm{ new DeepCoreMiner };
    IMiningLaser* sm{ new StripMiner };
    mb.equip(dcm);
    mb.equip(sm);

    IAsteroid* ab{ new AsteroBocal };
    IAsteroid* bs{ new BocalSteroid };
    mb.mine(ab);
    mb.mine(bs);

    delete ab;
    delete bs;
    return 0;
}