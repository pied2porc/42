#pragma once
#include "AMateria.h"
#include <string>

using str_t = std::string;

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}

    virtual str_t const& getName() const = 0;
    
    virtual void equip(AMateria*) = 0;
    virtual void unequip(int) = 0;
    virtual void use(int, ICharacter&) = 0;
};