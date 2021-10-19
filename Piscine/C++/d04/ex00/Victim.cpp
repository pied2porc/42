#include "Victim.h"

/* Constructors & Destructors */
Victim::Victim() {}

Victim::Victim(str_t const& name) :
    _name{ name }
{
    std::cout << "Some random victim called "
        << _name << " just popped !\n";
}

Victim::~Victim()
{
    std::cout << "Victim " << _name
        << " just died for no apparent reason !\n";
}

/* Copy & Assignment */
Victim::Victim(Victim const& src)
{
    *this = src;
    std::cout << "Some random victim called "
        << _name << " just popped !\n";
}

Victim& Victim::operator=(Victim const& rhs)
{
    // Gracefully handle self assignment
    _name = rhs._name;
    return *this;
}

/* Operator Overloads */
std::ostream& operator<<(std::ostream& out, Victim const& v)
{
    out << "I'm " << v.getName() << " and I like otters !\n";
    return out;
}

/* Getters & Setters */
str_t const& Victim::getName() const { return _name; }

/* Member Functions */
void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep !\n";
}