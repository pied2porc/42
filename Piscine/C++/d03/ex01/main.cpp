#include "FragTrap.h"
#include "ScavTrap.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "========================================"
                 "========================================\n";
    FragTrap    frag("Frag");
    ScavTrap    scav("Scav");

    std::cout << "\n";
    scav.challengeNewcomer(frag.get_name());
    unsigned int dmg{ frag.vaulthunter_dot_exe(scav.get_name()) };
    scav.takeDamage(dmg);
    scav.challengeNewcomer(frag.get_name());
    dmg = frag.vaulthunter_dot_exe(scav.get_name());
    scav.takeDamage(dmg);
    dmg = frag.vaulthunter_dot_exe(scav.get_name());
    scav.takeDamage(dmg);
    dmg = frag.vaulthunter_dot_exe(scav.get_name());
    scav.takeDamage(dmg);
    dmg = frag.vaulthunter_dot_exe(scav.get_name());
    scav.takeDamage(dmg);
    std::cout << "\n";

    return 0;
}