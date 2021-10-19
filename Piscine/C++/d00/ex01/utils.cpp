#include "utils.h"
#include <string>

str_t trunc(str_t s, size_t len, char c)
{
    if (s.size() <= len) return s;
    if (c)
        s[len - 1] = c;
    s.resize(len);
    return s;
}

str_t trim(str_t const& s, str_t const& cset)
{
    auto begin{ s.find_first_not_of(cset) };
    if (begin == str_t::npos) return "";

    auto end{ s.find_last_not_of(cset) };
    return s.substr(begin, end - begin + 1);
}