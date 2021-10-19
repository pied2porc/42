#include "Pony.h"
#include <string>
#include <iostream>

Pony::Pony(std::string const& name, int age) :
    m_name{ name }, m_age{ age }
{
    std::cout << m_name << " is born.\n";
}

Pony::~Pony()
{
    std::cout << m_name << " has died.\n";
}

void Pony::talk(std::string const& msg)
{
    std::cout << m_name << ": " << msg << '\n';
}