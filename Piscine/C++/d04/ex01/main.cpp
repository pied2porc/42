#include "AWeapon.h"
#include "Character.h"
#include "Enemy.h"
#include "PlasmaRifle.h"
#include "PowerFist.h"
#include "RadScorpion.h"
#include "SuperMutant.h"
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    Character* zaz = new Character("zaz");

    std::cout << *zaz;

    Enemy* s = new RadScorpion();
    Enemy* m = new SuperMutant();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    std::cout << "\n";
    
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);
    std::cout << *zaz;
    zaz->attack(&s);

    std::cout << "\n";
    zaz->equip(pr);
    while (s) {
        std::cout << *zaz;
        zaz->attack(&s);
    }
    zaz->attack(&s);
    std::cout << "\n";

    zaz->equip(pf);
    std::cout << *zaz;
    zaz->attack(&m);
    zaz->attack(&m);
    zaz->attack(&m);
    std::cout << *zaz;
    std::cout << "\n";

    zaz->recoverAP();
    zaz->recoverAP();
    zaz->recoverAP();
    zaz->recoverAP();
    std::cout << *zaz;
    std::cout << "\n";

    zaz->equip(pf);
    zaz->attack(&m);
    zaz->attack(&m);
    std::cout << *zaz;

    std::cout << "\n";
    delete zaz;
    delete pr;
    delete pf;
    
    return 0;
}