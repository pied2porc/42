#pragma once
#include "AMateria.h"
#include "ICharacter.h"
#include <string>

using str_t = std::string;

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(Ice const&);
    Ice& operator=(Ice const&);

    AMateria* clone() const;
    void      use(ICharacter&);
};