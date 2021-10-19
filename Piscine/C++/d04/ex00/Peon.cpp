#include "Peon.h"

Peon::Peon() {}

Peon::Peon(str_t const& name) : Victim(name)
{
    std::cout << "Zog zog.\n";
}

Peon::~Peon()
{
    std::cout << "Bleuark...\n";
}

Peon::Peon(Peon const& src) : Victim(src)
{
    std::cout << "Zog zog.\n";
}

Peon& Peon::operator=(Peon const& rhs)
{
    // Gracefully handle self assignment
    Victim::operator=(rhs);
    return *this;
}