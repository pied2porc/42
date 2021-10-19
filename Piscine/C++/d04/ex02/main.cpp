#include "AssaultTerminator.h"
#include "Squad.h"
#include "TacticalMarine.h"
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISpaceMarine* pat = new TacticalMarine;
    std::cout << "\n";

    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    vlc->push(pat);
    vlc->push(bob);
    vlc->push(jim->clone());
    for (int i{ 0 }; i < vlc->getCount(); ++i) {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    std::cout << "\n";
    
    std::cout << "Units: " << vlc->getCount() << "\n";
    vlc->getUnit(1)->battleCry();

    std::cout << "\n";
    delete vlc;
    return 0;
}