#pragma once
#include "Victim.h"
#include <iostream>

using str_t = std::string;

class Peon : public Victim
{
public:
    Peon();
    Peon(str_t const&);
    ~Peon();
    Peon(Peon const&);
    Peon& operator=(Peon const&);
};