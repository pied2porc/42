#pragma once
#include "Contact.h"
#include <array>
#include <string>

using str_t = std::string;

class Phonebook {
private:
    int                  m_nbContact{ 0 };
    static constexpr int m_maxContact{ 8 };
    std::array<Contact, m_maxContact> m_book;

    str_t&   get_info(str_t const&, str_t&);
    int      get_nb(str_t const&);

public:
    void     add_contact();
    Contact* search_contact();
    void     print();

    bool     isEmpty();
    bool     isFull();
};