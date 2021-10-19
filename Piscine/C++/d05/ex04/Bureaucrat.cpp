#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(str_t const& name, int grade) : _name{ name }
{
    if (grade < _highest)
        throw GradeTooHighException(_name);
    else if (grade > _lowest)
        throw GradeTooLowException(_name);
    _grade = grade;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const& src) { *this = src; }
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
    _grade = rhs._grade;
    return *this;
}

/* Operator Overloads */
Bureaucrat& Bureaucrat::operator++()
{
    if (_grade <= _highest)
        throw GradeTooHighException(_name);
    --_grade;
    return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
    if (_grade >= _lowest)
        throw GradeTooLowException(_name);
    ++_grade;
    return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
    if (_grade <= _highest)
        throw GradeTooHighException(_name);
    Bureaucrat tmp{ *this };
    ++(*this);
    return tmp;
}

Bureaucrat Bureaucrat::operator--(int)
{
    if (_grade >= _lowest)
        throw GradeTooLowException(_name);
    Bureaucrat tmp{ *this };
    --(*this);
    return tmp;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b)
{
    out << b.getName() << ", Bureaucrat <Grade " << b.getGrade() << ">\n";
    return out;
}

/* Getters & Setters */
str_t const& Bureaucrat::getName() const { return _name; }
int          Bureaucrat::getGrade() const { return _grade; }

/* Member Functions */
void Bureaucrat::signForm(Form& f)
{
    try {
        f.beSigned(*this);
    }
    catch (std::exception&) {
        std::cerr << "Bureaucrat " << _name << " cannot sign "
                  << f.getName() << " Form";
        throw SignException(_name);
    }
}

void Bureaucrat::executeForm(Form const& f)
{
    try {
        f.execute(*this);
    }
    catch (std::exception&) {
        std::cerr << "Bureaucrat " << _name << " cannot execute "
                  << f.getName() << " Form";
        throw ExecuteException(_name);
    }
}

/* Exceptions */
using B_GradeHighE = Bureaucrat::GradeTooHighException;
B_GradeHighE::GradeTooHighException(str_t const& whose) : _whose{ whose } {}
B_GradeHighE::~GradeTooHighException() {}
B_GradeHighE::GradeTooHighException(B_GradeHighE const& src) { *this = src; }
B_GradeHighE& B_GradeHighE::operator=(B_GradeHighE const&) { return *this; }
char const*   B_GradeHighE::what() const noexcept { return _msg.c_str(); }

using B_GradeLowE = Bureaucrat::GradeTooLowException;
B_GradeLowE::GradeTooLowException(str_t const& whose) : _whose{ whose } {}
B_GradeLowE::~GradeTooLowException() {}
B_GradeLowE::GradeTooLowException(B_GradeLowE const& src) { *this = src; }
B_GradeLowE& B_GradeLowE::operator=(B_GradeLowE const&) { return *this; }
char const*  B_GradeLowE::what() const noexcept { return _msg.c_str(); }

using B_SignE = Bureaucrat::SignException;
B_SignE::SignException(str_t const& whose) : _whose{ whose } {}
B_SignE::~SignException() {}
B_SignE::SignException(B_SignE const& src) { *this = src; }
B_SignE&    B_SignE::operator=(B_SignE const&) { return *this; }
char const* B_SignE::what() const noexcept { return _msg.c_str(); }

using B_ExecE = Bureaucrat::ExecuteException;
B_ExecE::ExecuteException(str_t const& whose) : _whose{ whose } {}
B_ExecE::~ExecuteException() {}
B_ExecE::ExecuteException(B_ExecE const& src) { *this = src; }
B_ExecE&    B_ExecE::operator=(B_ExecE const&) { return *this; }
char const* B_ExecE::what() const noexcept { return _msg.c_str(); }