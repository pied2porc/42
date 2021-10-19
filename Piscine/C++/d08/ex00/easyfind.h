#pragma once
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
size_t easyfind(T const& container, int n)
{
    auto begin{ std::begin(container) };
    auto end{ std::end(container) };
    auto res{ std::find(begin, end, n) };
    if (res == end)
        return std::string::npos;
    return std::distance(begin, res);
}