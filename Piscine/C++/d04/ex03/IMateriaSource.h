#pragma once
#include "AMateria.h"
#include <string>

using str_t = std::string;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}

    virtual void      learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(str_t const&) = 0;
};