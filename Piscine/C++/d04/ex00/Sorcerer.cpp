#include "Sorcerer.h"
#include "Victim.h"
#include <iostream>

/* Constructors & Destructors */
Sorcerer::Sorcerer(str_t const& name, str_t const& title) :
    _name{ name }, _title{ title }
{
    std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead."
              " Consequences will never be the same !\n";
}

/* Copy & Assignment */
Sorcerer::Sorcerer(Sorcerer const& src) { *this = src; }

Sorcerer& Sorcerer::operator=(Sorcerer const& rhs) {
    // Gracefully handle self assignment
    _name = rhs._name;
    _title = rhs._title;
    return *this;
}

/* Operator Overloads */
std::ostream& operator<<(std::ostream& out, Sorcerer const& s)
{
    out << "I am " << s.getName() << ", " << s.getTitle()
        << ", and I like ponies !\n";
    return out;
}

/* Getters & Setter */
str_t const& Sorcerer::getName() const { return _name; }
str_t const& Sorcerer::getTitle() const { return _title; }

/* Member Functions */
void Sorcerer::polymorph(Victim const& v) { v.getPolymorphed(); }