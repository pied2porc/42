#include "conversion.h"
#include <iostream>
#include <iomanip>

Scalar::Scalar(str_t const& s) : _literal{ s } {}
Scalar::~Scalar() {}
Scalar::Scalar(Scalar const& src) { *this = src; }
Scalar& Scalar::operator=(Scalar const&) { return *this; }

Scalar::operator char() const
{
    int value{ 0 };
    try {
        value = std::stoi(_literal);
        if (value < CHAR_MIN || value > CHAR_MAX)
            throw ImpossibleException();
        else if (!std::isprint(value))
            throw NonDiplayableException();
    }
    catch (std::exception&) {
        throw ImpossibleException();
    }
    return static_cast<char>(value);
}

Scalar::operator int() const
{
    int value{ 0 };
    try {
        value = std::stoi(_literal);
    }
    catch (std::exception&) {
        throw ImpossibleException();
    }
    return value;
}

Scalar::operator float() const
{
    float value{ 0 };
    try {
        value = std::stof(_literal);
    }
    catch (std::exception&) {
        throw ImpossibleException();
    }
    return value;
}

Scalar::operator double() const
{
    double value{ 0 };
    try {
        value = std::stod(_literal);
    }
    catch (std::exception&) {
        throw ImpossibleException();
    }
    return value;
}

int Scalar::getPrecision() const
{
    size_t pos{ _literal.find_first_of('.') };
    if (pos == std::string::npos)
        return 1;
    pos += 1;
    int digits{ 0 };
    while (std::isdigit(_literal[pos])) {
        ++pos; ++digits;
    }
    return digits ? digits : 1;
}

std::ostream& operator<<(std::ostream& out, Scalar const& s)
{
    out << "char: ";
    try {
        char c{ static_cast<char>(s) };
        std::cout << "'" << c << "'\n";
    }
    catch (Scalar::NonDiplayableException& e) {
        std::cerr << e.what() << "\n";
    }
    catch (Scalar::ImpossibleException& e) {
        std::cerr << e.what() << "\n";
    }
    out << "int: ";
    try {
        std::cout << static_cast<int>(s) << "\n";
    }
    catch (Scalar::ImpossibleException& e) {
        std::cerr << e.what() << "\n";
    }
    std::cout << std::fixed << std::setprecision(s.getPrecision());
    out << "float: ";
    try {
        std::cout << static_cast<float>(s) << "f\n";
    }
    catch (Scalar::ImpossibleException& e) {
        std::cerr << e.what() << "\n";
    }
    out << "double: ";
    try {
        std::cout << static_cast<double>(s) << "\n";
    }
    catch (Scalar::ImpossibleException& e) {
        std::cerr << e.what() << "\n";
    }
    return out;
}

/* Exceptions */
char const* Scalar::NonDiplayableException::what() const noexcept
{
    return "Non displayable";
}

char const* Scalar::ImpossibleException::what() const noexcept
{
    return "impossible";
}