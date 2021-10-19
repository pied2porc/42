#include "FragTrap.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "===================================="
                 "====================================\n";
    FragTrap    n{ "Nicolas" };
    FragTrap    x{ "Xavier" };
    {
        FragTrap    copy{ n };
        copy = x;
    }
    std::cout << "\n";
    unsigned int dmg{ n.vaulthunter_dot_exe(x.get_name()) };
    x.takeDamage(dmg);
    dmg = x.vaulthunter_dot_exe(n.get_name());
    n.takeDamage(dmg);

    std::cout << "\n";
    x.vaulthunter_dot_exe("Bouygues");
    x.vaulthunter_dot_exe("SFR");
    x.vaulthunter_dot_exe("Orange");

    std::cout << "\n\t\t*  *  *\n";
    n.beRepaired(42);
    n.beRepaired(1);
    std::cout << "\t\t*  *  *\n\n";

    dmg = x.vaulthunter_dot_exe(n.get_name());
    n.takeDamage(dmg);
    dmg = n.vaulthunter_dot_exe(x.get_name());
    x.takeDamage(dmg);
    dmg = n.vaulthunter_dot_exe(x.get_name());
    x.takeDamage(dmg);
    dmg = n.vaulthunter_dot_exe(x.get_name());
    x.takeDamage(dmg);
    std::cout << "\n";

    return 0;
}