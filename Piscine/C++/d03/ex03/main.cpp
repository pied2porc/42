#include "ClapTrap.h"
#include "FragTrap.h"
#include "NinjaTrap.h"
#include "ScavTrap.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    std::cout << "========================================"
                 "========================================\n";
    NinjaTrap n("Ninja");
    ClapTrap  c("Clap");
    FragTrap  f("Frag");
    ScavTrap  s("Scav");
    std::cout << "\n";

    n.ninjaShoebox(c);
    n.ninjaShoebox(f);
    n.ninjaShoebox(s);
    n.ninjaShoebox(n);
    
    std::cout << "\n";
    return 0;
}