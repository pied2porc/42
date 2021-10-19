#include "Token.h"
#include <exception>

Token::Token(int value, std::string const& type) : _value{ value }, _type{ type } {}
Token::~Token() {}
Token::Token(Token const& src) { *this = src; }
Token& Token::operator=(Token const& rhs) { _value = rhs._value; return *this; }

int                Token::getValue() const { return _value; }
std::string const& Token::getType() const { return _type; }

std::ostream& operator<<(std::ostream& out, Token const& t)
{
    try {
        auto& n{ dynamic_cast<Number const&>(t) };
        out << n;
        return out;
    }
    catch (std::bad_cast const&) {}
    try {
        auto& o{ dynamic_cast<Operator const&>(t) };
        out << o;
        return out;
    }
    catch (std::bad_cast const&) {}
    try {
        auto& p{ dynamic_cast<Parenthesis const&>(t) };
        out << p;
        return out;
    }
    catch (std::bad_cast const&) {}
    return out;
}

Number::Number(int n) : Token(n, "Num") {}
size_t Number::getDigits() const { return _digits; }
void   Number::setDigits(size_t digits) { _digits = digits; }
std::ostream& operator<<(std::ostream& out, Number const& n)
{
    out << n.getType() << '(' << n.getValue() << ')';
    return out;
}

Operator::Operator(int o) : Token(o, "Op") {}
std::ostream& operator<<(std::ostream& out, Operator const& o)
{
    out << o.getType() << '('
        << static_cast<char>(o.getValue()) << ')';
    return out;
}

Parenthesis::Parenthesis(int p) : Token(p, "Par") {}
std::ostream& operator<<(std::ostream& out, Parenthesis const& p)
{
    out << p.getType() << (p.getValue() == '(' ? "Open" : "Close");
    return out;
}