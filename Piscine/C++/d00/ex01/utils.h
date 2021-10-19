#pragma once
#include <string>

using str_t = std::string;

str_t trim(const str_t&, const str_t&);
str_t trunc(str_t, size_t, char = 0);