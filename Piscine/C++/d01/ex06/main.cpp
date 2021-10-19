#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

int main()
{
    {
        Weapon  club{ "crude spiked club" };

        HumanA   bob{ "Bob", club };
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon  club{ "crude spiked club" };

        HumanB   jim{ "jim" };
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}