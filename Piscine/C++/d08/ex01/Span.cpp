#include "Span.h"
#include <algorithm>
#include <exception>

int rng(int, int);

Span::Span(unsigned int n) : _arr{ std::vector<int>(n) }, _maxSize{ n } {}

Span::~Span() {}

Span::Span(Span const& src) { *this = src; }

Span& Span::operator=(Span const& rhs)
{
    if (this == &rhs) return *this;

    _maxSize = rhs._maxSize;
    _lastPos = rhs._lastPos;
    _arr = rhs._arr;
    return *this;
}

void Span::addNumber(int n)
{
    if (!(_lastPos < _maxSize))
        throw std::overflow_error("container is full");
    _arr[_lastPos++] = n;
}

void Span::fillNumber(int min, int max)
{
    for (auto& e : _arr) {
        e = rng(min, max);
        ++_lastPos;
    }
}

int Span::shortestSpan()
{
    if (_lastPos <= 1)
        throw std::runtime_error("not enough values");  
    std::vector<int> cpy{ _arr };
    std::sort(cpy.begin(), cpy.end());

    int  shortest{ INT_MAX };
    auto prev{ cpy.begin() };
    auto next{ std::next(cpy.begin()) };
    auto end{ cpy.end() };
    for (; next != end; ++next, ++prev) {
        int span{ *next - *prev };
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_lastPos <= 1)
        throw std::runtime_error("not enough values");
 
    return (*std::max_element(_arr.begin(), _arr.end()) -
            *std::min_element(_arr.begin(), _arr.end()));
}

std::vector<int>const& Span::getArray() const { return _arr; }

std::ostream& operator<<(std::ostream& out, Span const& s)
{
    for (auto n : s.getArray())
        out << n << ' ';
    return out;
}