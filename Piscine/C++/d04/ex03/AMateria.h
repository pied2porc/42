#pragma once
#include "ICharacter.h"
#include <string>

using str_t = std::string;

class AMateria
{
private:
    str_t        _type{ "???" };
    unsigned int _xp{ 0 };

public:
    AMateria();
    AMateria(str_t const&);
    virtual ~AMateria();

    AMateria(AMateria const&);
    AMateria& operator=(AMateria const&);

    str_t const&      getType() const;
    unsigned int      getXP() const;

    virtual AMateria* clone() const = 0;
    virtual void      use(ICharacter&);
};