#pragma once
#include "Brain.h"

class Human
{
    Brain const* m_brain{ new Brain };

public:
    ~Human();

    Brain const& getBrain() const;
    str_t const& identify() const;
};