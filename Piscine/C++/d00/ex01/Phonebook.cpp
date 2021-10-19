#include "Contact.h"
#include "Phonebook.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <string>

str_t& Phonebook::get_info(str_t const & prompt, str_t& input)
{
    std::cout << prompt;
    std::getline(std::cin, input);
    return (input = trim(input, " \t"));
}

int Phonebook::get_nb(str_t const& s)
{
    if (!s.empty() &&
        s.find_first_not_of("0123456789") == str_t::npos)
        return stoi(s);
    return -1;
}

void Phonebook::add_contact()
{
    Contact& c{ m_book[m_nbContact] };
    str_t    info;
    size_t   pos;
    int      nb{};
    while (get_info("First name> ", info).empty());
    c.set_fname(info);
    c.set_lname(get_info("Last name> ", info));
    c.set_nickname(get_info("Nickname> ", info));
    c.set_login(get_info("Login> ", info));
    c.set_address(get_info("Postal address> ", info));
    while (!get_info("Email address> ", info).empty())
        if (((pos = info.find('@', 1)) != str_t::npos &&
            info.find('.', pos + 1) != str_t::npos) &&
            pos < info.size() - 1) break;
    c.set_email(info);
    while (!get_info("Phone number> ", info).empty())
        if (info.find_first_not_of("0123456789") == str_t::npos) break;
    c.set_phone(info);
    while (!get_info("Birthday day (DD)> ", info).empty())
        if ((nb = get_nb(info)) >= 1 && nb <= 31) {
            c.set_bday(nb);
            while (!get_info("Birthday month (MM)> ", info).empty())
                if ((nb = get_nb(info)) >= 1 && nb <= 12) {
                    c.set_bmonth(nb);
                    while (!get_info("Birthday year (YYYY)> ", info).empty())
                        if ((nb = get_nb(info)) >= 1900) {
                            c.set_byear(nb);
                            break;
                        }
                    break;
                }
            break;
        }
    c.set_favMeal(get_info("Favorite meal> ", info));
    c.set_uwColor(get_info("Underwear color> ", info));
    c.set_secret(get_info("Darkest secret> ", info));
    c.set_id(m_nbContact++);
}

Contact* Phonebook::search_contact()
{
    int id{ -1 };
    while (id < 0 || id > m_nbContact - 1) {
        std::cout << "Enter index> ";
        str_t input;
        std::getline(std::cin, input);
        if (input == "exit")
            return nullptr;
        else
            id = get_nb(input);
    }
    return &m_book[id];
}

void Phonebook::print()
{
    std::cout << '\n';
    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First name" << '|';
    std::cout << std::setw(10) << "Last name" << '|';
    std::cout << std::setw(10) << "Nickname" << '\n';
    std::cout << "----------|----------|----------|----------" << '\n';

    for (auto c : m_book) {
        if (c.get_id() < 0) break;
        std::cout << std::setfill(' ');
        std::cout << std::setw(10) << c.get_id() << '|';
        std::cout << std::setw(10) << trunc(c.get_fname(), 10, '.') << '|';
        std::cout << std::setw(10) << trunc(c.get_lname(), 10, '.') << '|';
        std::cout << std::setw(10) << trunc(c.get_nickname(), 10, '.') << '\n';
    }
    std::cout << "-------------------------------------------" << '\n';
}

bool Phonebook::isEmpty() { return !m_nbContact ? true : false; }
bool Phonebook::isFull() { return m_nbContact >= m_maxContact ? true : false; }