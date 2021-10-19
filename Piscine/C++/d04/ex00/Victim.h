#pragma once
#include <string>
#include <iostream>

using str_t = std::string;

class Victim
{
protected:
    str_t   _name;

public:
    Victim();
    Victim(str_t const&);
    ~Victim();

    Victim(Victim const&);
    Victim& operator=(Victim const&);

    str_t const& getName() const;

    void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream&, Victim const&);