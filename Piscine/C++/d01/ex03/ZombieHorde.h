#pragma once
#include "Zombie.h"

using str_t = std::string;

int getRandomNumber(int, int);

class ZombieHorde
{
    Zombie* m_horde;
    size_t  m_size;

public:
    ZombieHorde(std::size_t);
    ~ZombieHorde();

    void announce();
};