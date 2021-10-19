#pragma once
#include "Zombie.h"
#include <string>

using str_t = std::string;

class ZombieEvent
{
    str_t m_type{"???"};

public:
    void    setZombieType(const str_t&);
    Zombie* newZombie(const str_t&);
};