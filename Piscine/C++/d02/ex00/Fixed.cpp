#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawVal{ 0 }
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) : _rawVal{ n << _binPt }
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const n) : _rawVal{ (int)roundf(n * (1 << _binPt)) }
{
    std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const& src) : _rawVal{ src._rawVal }
{
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    _rawVal = rhs._rawVal;
    std::cout << "Assignation operator called\n";
    return *this;
}

int  Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return _rawVal;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    _rawVal = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_rawVal / (1 << _binPt));
}

int Fixed::toInt(void) const
{
    return _rawVal >> _binPt;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed)
{
    out << fixed.toFloat();
    return out;
}