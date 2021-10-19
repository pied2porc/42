#pragma once
#include "Form.h"
#include <iostream>
#include <string>

using str_t = std::string;

class Form;

class Bureaucrat
{
private:
    static int constexpr _highest{ 1 };
    static int constexpr _lowest{ 150 };

    str_t const _name{"noname"};
    int         _grade{ _lowest };

public:
    Bureaucrat();
    Bureaucrat(str_t const&, int);
    ~Bureaucrat();

    Bureaucrat(Bureaucrat const&);
    Bureaucrat& operator=(Bureaucrat const&);
    
    Bureaucrat& operator++();
    Bureaucrat& operator--();
    Bureaucrat  operator++(int);
    Bureaucrat  operator--(int);

    str_t const& getName() const;
    int          getGrade() const;

    void         signForm(Form&);

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

std::ostream& operator<<(std::ostream&, Bureaucrat const&);