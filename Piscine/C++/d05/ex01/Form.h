#pragma once
#include "Bureaucrat.h"
#include <string>
#include <iostream>

using str_t = std::string;

class Bureaucrat;

class Form
{
private:
    static int constexpr _highest{ 1 };
    static int constexpr _lowest{ 150 };

    str_t const _name{ "???" };
    int   const _signGrade{ _lowest };
    int   const _execGrade{ _lowest };
    bool        _signed{ false };

public:
    Form();
    Form(str_t const&, int, int);
    virtual ~Form();
    Form(Form const&);
    Form& operator=(Form const&);

    str_t const& getName() const;
    int          getSignGrade() const;
    int          getExecGrade() const;
    bool         isSigned() const;

    void         beSigned(Bureaucrat const&);

    class GradeTooHighException : public std::exception
    {
        str_t const _whose{};
        str_t const _msg{ _whose + "'s grade is too high" };
    public:
        GradeTooHighException(str_t const&);
        ~GradeTooHighException();
        GradeTooHighException(GradeTooHighException const&);
        GradeTooHighException& operator=(GradeTooHighException const&);

        char const* what() const noexcept;
    };

    class GradeTooLowException : public std::exception
    {
        str_t const _whose{};
        str_t const _msg{ _whose + "'s grade is too low" };
    public:
        GradeTooLowException(str_t const&);
        ~GradeTooLowException();
        GradeTooLowException(GradeTooLowException const&);
        GradeTooLowException& operator=(GradeTooLowException const&);

        char const* what() const noexcept;
    };
};

std::ostream& operator<<(std::ostream&, Form const&);
str_t         titleCase(str_t);