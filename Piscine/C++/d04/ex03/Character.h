#pragma once
#include "AMateria.h"
#include "ICharacter.h"
#include <iostream>

class Character : public ICharacter
{
private:
    static int constexpr _invSize{ 4 };
    
    str_t     _name{ "noname" };
    AMateria* _inventory[_invSize]{ nullptr };

public:
    Character();
    Character(str_t const&);
    ~Character();

    Character(Character const&);
    Character& operator=(Character const&);
    void       deepCopy(Character const&);

    str_t const&    getName() const;
    AMateria*       getMateria(int) const;
    int             getInvSize() const;

    void            equip(AMateria*);
    void            unequip(int);
    void            use(int, ICharacter&);
};

std::ostream& operator<<(std::ostream&, Character const&);