#pragma once
#include "Victim.h"
#include <string>
#include <iostream>

using str_t = std::string;

class Sorcerer
{
private:
    str_t   _name{ "???" };
    str_t   _title{ "???" };

public:
    Sorcerer() = delete;
    Sorcerer(str_t const&, str_t const&);
    ~Sorcerer();

    Sorcerer(Sorcerer const&);
    Sorcerer& operator=(Sorcerer const&);

    str_t const& getName() const;
    str_t const& getTitle() const;

    void    polymorph(Victim const&);
};

std::ostream& operator<<(std::ostream&, Sorcerer const&);