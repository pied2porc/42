#include "Weapon.h"

Weapon::Weapon(str_t const& type) : m_type{ type } {}

str_t const& Weapon::getType() const { return m_type; }
void Weapon::setType(str_t const& type) { m_type = type; }