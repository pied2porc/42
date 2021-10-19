#include "FragTrap.h"
#include "NinjaTrap.h"
#include "ScavTrap.h"
#include "SuperTrap.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    std::cout << "========================================"
                 "========================================\n";
    SuperTrap sup("Super");
    std::cout << "\n";
    ScavTrap  sca("Scav");
    std::cout << "\n";

    int dmg;
    dmg = sup.rangedAttack(sca.get_name());
    sca.takeDamage(dmg);
    dmg = sup.meleeAttack(sca.get_name());
    sca.takeDamage(dmg);

    std::cout << "\n";
    return 0;
}