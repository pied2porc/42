#include "AMateria.h"
#include "Cure.h"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}

Cure::Cure(Cure const& src) : AMateria(src) {}
Cure& Cure::operator=(Cure const& rhs)
{
    AMateria::operator=(rhs);
    return *this;
}

AMateria* Cure::clone() const { return new Cure; }
void      Cure::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}