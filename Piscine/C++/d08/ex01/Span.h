#pragma once
#include <iostream>
#include <vector>

class Span
{
private:
    unsigned int     _maxSize{ 0 };
    unsigned int     _lastPos{ 0 };
    std::vector<int> _arr;

public:
    Span(unsigned int = 0);
    ~Span();
    Span(Span const&);
    Span& operator=(Span const&);

    std::vector<int>const& getArray() const;

    void addNumber(int);
    void fillNumber(int = 0, int = INT_MAX);
    int  shortestSpan();
    int  longestSpan();
};

std::ostream& operator<<(std::ostream&, Span const&);