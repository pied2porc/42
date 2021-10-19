#pragma once
#include <iostream>

class Fixed
{
    int              _rawVal{ 0 };
    static int const _binPt{ 8 };

public:
    Fixed();
    Fixed(int const);
    Fixed(float const);
    ~Fixed();
    Fixed(Fixed const&); // copy constructor

    Fixed& operator=(Fixed const&);

    int     getRawBits(void) const;
    void    setRawBits(int const);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream& operator<<(std::ostream&, Fixed const&);