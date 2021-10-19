#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawVal{ 0 } {}
Fixed::Fixed(int const n) : _rawVal{ n << _binPt } {}
Fixed::Fixed(float const n) : _rawVal{ (int)roundf(n * (1 << _binPt)) } {}
Fixed::Fixed(double const n) : _rawVal{ (int)(n * (1 << _binPt)) } {}
Fixed::~Fixed() {}
Fixed::Fixed(Fixed const& src) : _rawVal{ src._rawVal } {}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    _rawVal = rhs._rawVal;
    return *this;
}

bool Fixed::operator==(Fixed const& rhs) const { return _rawVal == rhs._rawVal; }
bool Fixed::operator!=(Fixed const& rhs) const { return !(*this == rhs); }
bool Fixed::operator< (Fixed const& rhs) const { return _rawVal < rhs._rawVal; }
bool Fixed::operator> (Fixed const& rhs) const { return rhs < *this; }
bool Fixed::operator<=(Fixed const& rhs) const { return !(*this > rhs); }
bool Fixed::operator>=(Fixed const& rhs) const { return !(*this < rhs); }

Fixed& Fixed::operator+(Fixed const& rhs)
{
    _rawVal += rhs._rawVal;
    return *this;
}

Fixed& Fixed::operator-(Fixed const& rhs)
{
    _rawVal -= rhs._rawVal;
    return *this;
}

Fixed& Fixed::operator*(Fixed const& rhs)
{
    (_rawVal *= rhs._rawVal) >>= _binPt;
    return *this;
}

Fixed& Fixed::operator/(Fixed const& rhs)
{
    (_rawVal <<= _binPt) /= rhs._rawVal;
    return *this;
}

Fixed& Fixed::operator++()
{
    ++_rawVal;
    return *this;
}

Fixed& Fixed::operator--()
{
    --_rawVal;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp{ *this };
    ++(*this);
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp{ *this };
    --(*this);
    return tmp;
}

int   Fixed::getRawBits(void) const { return _rawVal; }
void  Fixed::setRawBits(int const raw) { _rawVal = raw; }
float Fixed::toFloat(void) const { return ((float)_rawVal / (1 << _binPt)); }
int   Fixed::toInt(void) const { return _rawVal >> _binPt; }

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    return lhs > rhs ? lhs : rhs;
}

Fixed const& Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

Fixed const& Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
    return lhs > rhs ? lhs : rhs;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed)
{
    out << fixed.toFloat();
    return out;
}