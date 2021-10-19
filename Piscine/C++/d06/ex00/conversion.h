#pragma once
#include <iostream>
#include <string>

using str_t = std::string;

class Scalar {
    str_t   _literal{};

public:
    Scalar(str_t const&);
    ~Scalar();
    Scalar(Scalar const&);
    Scalar& operator=(Scalar const&);

    operator char() const;
    operator int() const;
    operator float() const;
    operator double() const;

    int getPrecision() const;

    /* Exceptions */
    class NonDiplayableException : public std::exception {
    public:
        char const* what() const noexcept;
    };

    class ImpossibleException : public std::exception {
    public:
        char const* what() const noexcept;
    };
};

std::ostream& operator<<(std::ostream&, Scalar const&);