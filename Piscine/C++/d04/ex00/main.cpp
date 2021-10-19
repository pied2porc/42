#include "Peon.h"
#include "Sorcerer.h"
#include "Victim.h"
#include <iostream>

int main()
{
    Sorcerer robert{ "Robert", "the Magnificent" };
    Victim   jim{ "Jimmy" };
    Peon     joe{ "Joe" };
    Peon     tom{ "Tom" };

    std::cout << robert << jim << joe << tom;

    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(tom);

    Peon copy{ tom };
    copy = joe;

    return 0;
}