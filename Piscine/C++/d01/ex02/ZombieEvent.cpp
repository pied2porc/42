#include "ZombieEvent.h"

void ZombieEvent::setZombieType(str_t const& type)
{
    m_type = type;
}

Zombie* ZombieEvent::newZombie(str_t const& name)
{
    return new Zombie{ name, m_type };
}