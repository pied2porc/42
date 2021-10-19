#pragma once
#include <iostream>
#include <string>

////////
class Token
{
protected:
    int         _value{};
    std::string _type;

public:
    Token(int, std::string const&);
    virtual ~Token();
    Token(Token const&);
    Token& operator=(Token const&);

    int                getValue() const;
    std::string const& getType() const;
};
std::ostream& operator<<(std::ostream&, Token const&);

////////
class Number : public Token
{
    size_t _digits{};

public:
    Number(int);
    size_t getDigits() const;
    void   setDigits(size_t);
};
std::ostream& operator<<(std::ostream&, Number const&);

////////
class Operator : public Token
{
public:
    Operator(int);
};
std::ostream& operator<<(std::ostream&, Operator const&);

////////
class Parenthesis : public Token
{
public:
    Parenthesis(int);
};
std::ostream& operator<<(std::ostream&, Parenthesis const&);