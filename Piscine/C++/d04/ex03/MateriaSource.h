#pragma once
#include "IMateriaSource.h"
#include "AMateria.h"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    static int constexpr _size{ 4 };
    AMateria* _source[_size]{ nullptr };

public:
    MateriaSource();
    ~MateriaSource();

    MateriaSource(MateriaSource const&);
    MateriaSource& operator=(MateriaSource const&);
    void           deepCopy(MateriaSource const&);

    AMateria* getMateria(int) const;
    int       getSize() const;

    void      learnMateria(AMateria*);
    AMateria* createMateria(str_t const&);
};

std::ostream& operator<<(std::ostream&, MateriaSource const&);