#include "AMateria.h"
#include "MateriaSource.h"
#include <iostream>

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() { for (auto& m : _source) delete m; }

MateriaSource::MateriaSource(MateriaSource const& src) { deepCopy(src); }

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
    if (this != &rhs)
        deepCopy(rhs);
    return *this;
}

void MateriaSource::deepCopy(MateriaSource const& src)
{
    int i{ -1 };
    for (auto& m : _source){
        delete m;
        m = src._source[++i] ? src._source[i]->clone() : nullptr;
    }
}

std::ostream& operator<<(std::ostream& out, MateriaSource const& s)
{
    for (int i{ 0 }; i < s.getSize(); ++i)
        if (auto m = s.getMateria(i))
            out << m->getType() << "(" << m->getXP() << ") ";
    return out;
}

/* Getters & Setters */
AMateria* MateriaSource::getMateria(int idx) const { return _source[idx]; }
int       MateriaSource::getSize() const { return _size; }

/* Member Functions */
void MateriaSource::learnMateria(AMateria* materia)
{
    for (auto& m : _source)
        if (!m) {
            m = materia->clone();
            return;
        }
}

AMateria* MateriaSource::createMateria(str_t const& type)
{
    for (auto m : _source){
        if (m && m->getType() == type)
            return m->clone();
    }
    return nullptr;
}