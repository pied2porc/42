#include "AMateria.h"
#include "Ice.h"
#include <iostream>

Ice::Ice() : AMateria("ice") {}
Ice::~Ice() {}

Ice::Ice(Ice const& src) : AMateria(src) {}
Ice& Ice::operator=(Ice const& rhs)
{
    AMateria::operator=(rhs);
    return *this;
}

AMateria* Ice::clone() const { return new Ice; }
void      Ice::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}