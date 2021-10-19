#include "Zombie.h"
#include <iostream>

Zombie::Zombie() : Zombie("noname", "???") {}

Zombie::Zombie(str_t const& name, str_t const& type) :
    m_name{ name }, m_type{ type }
{
    std::cout << m_name << " has been spawned\n";
}

Zombie::~Zombie()
{
    std::cout << m_name << " has died\n";
}

void Zombie::announce(str_t const& msg)
{
    std::cout << "<" << m_name << " (" << m_type << ")> "
        << msg << "\n";
}

void Zombie::set_name(str_t const& name) { m_name = name; }
void Zombie::set_type(str_t const& type) { m_type = type; }

str_t const& Zombie::get_name() const { return m_name; }
str_t const& Zombie::get_type() const { return m_type; }