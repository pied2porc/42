#include "FragTrap.h"
#include "ScavTrap.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    std::cout << "========================================"
                 "========================================\n";
    ScavTrap s("Scav");
    FragTrap f("Frag");
    { ScavTrap copy{ s }; }
    std::cout << "\n";
    
    int dmg{};
    s.challengeNewcomer(f.get_name());
    dmg = f.meleeAttack(s.get_name());
    s.takeDamage(dmg);
    dmg = s.meleeAttack(f.get_name());
    f.takeDamage(dmg);
    dmg = s.rangedAttack(f.get_name());
    f.takeDamage(dmg);
    dmg = f.vaulthunter_dot_exe(s.get_name());
    s.takeDamage(dmg);
    dmg = f.vaulthunter_dot_exe(s.get_name());
    s.takeDamage(dmg);

    std::cout << "\n";
    return 0;
}