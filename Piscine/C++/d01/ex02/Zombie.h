#pragma once
#include <string>

using str_t = std::string;

class Zombie
{
    str_t m_name{ "noname" };
    str_t m_type{ "???" };

public:
    Zombie(void);
    Zombie(str_t const&, str_t const&);
    ~Zombie();

    void announce(str_t const&);
    void set_name(str_t const&);
    void set_type(str_t const&);

    str_t const& get_name() const;
    str_t const& get_type() const;
};