#pragma once
#include "AMateria.h"
#include "ICharacter.h"
#include <string>

using str_t = std::string;

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(Cure const&);
    Cure& operator=(Cure const&);
  
    AMateria* clone() const;
    void      use(ICharacter&);
};