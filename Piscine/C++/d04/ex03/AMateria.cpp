#include "AMateria.h"
#include "ICharacter.h"

AMateria::AMateria() {};
AMateria::AMateria(str_t const& type) : _type{ type } {}
AMateria::~AMateria() {}

AMateria::AMateria(AMateria const& src) { *this = src; }
AMateria& AMateria::operator=(AMateria const& rhs)
{
    _xp = rhs._xp;
    return *this;
}

str_t const& AMateria::getType() const { return _type; }
unsigned int AMateria::getXP() const { return _xp; }

void         AMateria::use(ICharacter&) { _xp += 10; }