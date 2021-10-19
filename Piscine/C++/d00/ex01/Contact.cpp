#include "Contact.h"
#include "utils.h"
#include <iostream>
#include <iomanip>

void Contact::set_id(int id)             { m_id = id; }
void Contact::set_fname(str_t& input)    { m_fname    = input; }
void Contact::set_lname(str_t& input)    { m_lname    = input; }
void Contact::set_nickname(str_t& input) { m_nname    = input; }
void Contact::set_login(str_t& input)    { m_login    = input; }
void Contact::set_address(str_t& input)  { m_address  = input; }
void Contact::set_email(str_t& input)    { m_email    = input; }
void Contact::set_phone(str_t& input)    { m_phone    = input; }
void Contact::set_bday(int input)        { m_bday     = input; }
void Contact::set_bmonth(int input)      { m_bmonth   = input; }
void Contact::set_byear(int input)       { m_byear    = input; }
void Contact::set_favMeal(str_t& input)  { m_favMeal  = input; }
void Contact::set_uwColor(str_t& input)  { m_uwColor  = input; }
void Contact::set_secret(str_t& input)   { m_secret   = input; }

const    int Contact::get_id() const       { return m_id; }
const str_t& Contact::get_fname() const    { return m_fname; }
const str_t& Contact::get_lname() const    { return m_lname; }
const str_t& Contact::get_nickname() const { return m_nname; }

void Contact::print() const
{
    std::cout << '\n';
    std::cout << "[Family name]: "      << m_fname    << '\n';
    std::cout << "[Last name]: "        << m_lname    << '\n';
    std::cout << "[Nickname]: "         << m_nname    << '\n';
    std::cout << "[Login]: "            << m_login    << '\n';
    std::cout << "[Postal address]: "   << m_address  << '\n';
    std::cout << "[Email address]: "    << m_email    << '\n';
    std::cout << "[Phone number]: "     << m_phone    << '\n';
    std::cout << "[Birthday date]: ";
    if (m_bday && m_bmonth && m_byear)
        std::cout << std::setfill('0') << std::setw(2) << m_bday << '/'
                  << std::setw(2) << m_bmonth << '/' << m_byear;
    std::cout << '\n';
    std::cout << "[Favorite meal]: "    << m_favMeal  << '\n';
    std::cout << "[Underwear color]: "  << m_uwColor  << '\n';
    std::cout << "[Darkest secret]: "   << m_secret   << '\n';
    std::cout << '\n';
}