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
    Fixed(double const);
    ~Fixed();
    Fixed(Fixed const&); // copy constructor

    Fixed&  operator= (Fixed const&);
    bool    operator==(Fixed const&) const;
    bool    operator!=(Fixed const&) const;
    bool    operator< (Fixed const&) const;
    bool    operator> (Fixed const&) const;
    bool    operator<=(Fixed const&) const;
    bool    operator>=(Fixed const&) const;

    Fixed&  operator+(Fixed const&);
    Fixed&  operator-(Fixed const&);
    Fixed&  operator*(Fixed const&);
    Fixed&  operator/(Fixed const&);

    Fixed&  operator++(); // prefix
    Fixed&  operator--();
    Fixed   operator++(int); // postfix
    Fixed   operator--(int);

    int     getRawBits(void) const;
    void    setRawBits(int const);
    float   toFloat(void) const;
    int     toInt(void) const;

    static Fixed&       min(Fixed&, Fixed&);
    static Fixed&       max(Fixed&, Fixed&);
    static Fixed const& min(Fixed const&, Fixed const&);
    static Fixed const& max(Fixed const&, Fixed const&);
};

std::ostream& operator<<(std::ostream&, Fixed const&);