#include "serialize.h"
#include <ctime>
#include <random>
#include <iostream>

namespace Rng {
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int rand(int min, int max)
{
    std::uniform_int_distribution dist{ min, max };
    return dist(Rng::mt);
}

void* serialize(void)
{
    static const str_t alphanum{
    "0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    int constexpr size{ 8 * 2 + sizeof(int) };
    char* ptr{ new char[size] };
    
    for (int i{ 0 }; i < size; ++i)
        if (i < 8 || i >= 12)
            ptr[i] = alphanum[rand(0, alphanum.size() - 1)];
    *reinterpret_cast<int*>(ptr + 8) = rand(0, INT_MAX);
    
    return ptr;
}

Data* deserialize(void* raw)
{
    Data* data{ new Data };

    char* ptr{ reinterpret_cast<char*>(raw) };
    data->s1.assign(ptr, 8);
    data->n = *reinterpret_cast<int*>(ptr + 8);
    data->s2.assign(ptr + 12, 8);

    return data;
}