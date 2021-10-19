#pragma once
#include <string>

class Pony
{
public:
    std::string m_name;
    int         m_age{};

    Pony(std::string const&, int);
    ~Pony();
    
    void talk(std::string const&);
};

void ponyOnTheHeap();
void ponyOnTheStack();