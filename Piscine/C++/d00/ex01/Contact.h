#pragma once
#include <string>

using str_t = std::string;

class Contact {
private:
    int   m_id{ -1 };
    str_t m_fname;
    str_t m_lname;
    str_t m_nname;
    str_t m_login;
    str_t m_address;
    str_t m_email;
    str_t m_phone;
    int   m_bday{};
    int   m_bmonth{};
    int   m_byear{};
    str_t m_favMeal;
    str_t m_uwColor;
    str_t m_secret;

public:
    void set_id(int);
    void set_fname(str_t&);
    void set_lname(str_t&);
    void set_nickname(str_t&);
    void set_login(str_t&);
    void set_address(str_t&);
    void set_email(str_t&);
    void set_phone(str_t&);
    void set_bday(int);
    void set_bmonth(int);
    void set_byear(int);
    void set_favMeal(str_t&);
    void set_uwColor(str_t&);
    void set_secret(str_t&);

    const int    get_id() const;
    const str_t& get_fname() const;
    const str_t& get_lname() const;
    const str_t& get_nickname() const;
    void         print() const;
};