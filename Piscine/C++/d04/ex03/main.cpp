#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    MateriaSource* src = new MateriaSource;
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);
    std::cout << "[source]: " << *src << "\n";
    MateriaSource src2{ *src };
    std::cout << "[source2]: " << src2 << "\n\n";

    Character* zaz = new Character("zaz");
    Character* bob = new Character("bob");
    AMateria* ice{ nullptr };
    AMateria* cure{ nullptr };

    ice = src->createMateria("ice");
    zaz->equip(ice);
    cure = src->createMateria("cure");
    zaz->equip(cure);
    cure = src->createMateria("cure");
    zaz->equip(cure);

    std::cout << "[" << zaz->getName() << "]: " << *zaz << "\n";
    zaz->use(0, *bob);
    zaz->use(1, *bob);
    std::cout << "[" << zaz->getName() << "]: " << *zaz << "\n\n";

    if (cure && ice)
        *cure = *ice;
    zaz->equip(cure);
    zaz->use(2, *bob);
    std::cout << "[" << zaz->getName() << "]: " << *zaz << "\n\n";

    bob->equip(cure);
    std::cout << "[" << bob->getName() << "]: " << *bob << "\n";
    Character copy{ *bob };
    std::cout << "[" << copy.getName() << " clone]: " << copy << "\n\n";

    *bob = *zaz;
    std::cout << "[" << zaz->getName() << "]: " << *zaz << "\n";
    std::cout << "[bob=" << bob->getName() << "]: " << *bob << "\n";
    bob->unequip(42);
    bob->unequip(3);
    bob->unequip(3);
    bob->unequip(0);
    std::cout << "[bob=" << bob->getName() << "]: " << *bob << "\n\n";

    bob->use(0, *zaz);
    bob->use(1, *zaz);
    bob->equip(ice);
    bob->use(0, *zaz);
    std::cout << "[bob=" << bob->getName() << "]: " << *bob << "\n";
    std::cout << "[" << zaz->getName() << "]: " << *zaz << "\n\n";

    delete bob;
    delete zaz;
    delete src;
    delete ice;
    delete cure;
    return 0;
}