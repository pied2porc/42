#pragma once
#include <string>

using str_t = std::string;

struct Data {
    str_t s1;
    int   n;
    str_t s2;
};

int     rand(int, int);
void*   serialize(void);
Data*   deserialize(void*);