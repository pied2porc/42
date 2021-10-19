#pragma once
#include "Form.h"
#include <string>

using str_t = std::string;

class Intern
{
private:
    using mfn_t = Form* (Intern::*)(str_t const&) const;
    typedef struct s_form {
        str_t name;
        mfn_t mfn;
    } t_form;

    static const t_form _forms[];

    Form* makePPF(str_t const&) const;
    Form* makeRRF(str_t const&) const;
    Form* makeSCF(str_t const&) const;

public:
    Intern();
    ~Intern();
    Intern(Intern const&);
    Intern& operator=(Intern const&);

    Form* makeForm(str_t const&, str_t const&) const;

    class UnknownFormException : public std::exception
    {
        str_t const _name{};
        str_t const _msg{ _name + " Form is unknown" };
    public:
        UnknownFormException(str_t const&);
        ~UnknownFormException();
        UnknownFormException(UnknownFormException const&);
        UnknownFormException& operator=(UnknownFormException const&);

        char const* what() const noexcept;
    };
};