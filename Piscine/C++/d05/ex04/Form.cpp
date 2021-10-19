#include "Form.h"

Form::Form() {}
Form::Form(str_t const& name, str_t const& target,
           int signGrade, int execGrade) :
    _name{ titleCase(name) }, _target{ target },
    _signGrade{ signGrade }, _execGrade{ execGrade }
{
    if (_signGrade < _highest || _execGrade < _highest)
        throw GradeTooHighException(_name);
    else if (_signGrade > _lowest || _execGrade > _lowest)
        throw GradeTooLowException(_name);
}
Form::~Form() {}

Form::Form(Form const& src) { *this = src; }
Form& Form::operator=(Form const&) { return *this; }

/* Getters & Setters */
str_t const& Form::getName() const { return _name; }
str_t const& Form::getTarget() const { return _target; }
int          Form::getSignGrade() const { return _signGrade; }
int          Form::getExecGrade() const { return _execGrade; }
bool         Form::isSigned() const { return _signed; }

/* Member Functions */
void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > _signGrade)
        throw Bureaucrat::GradeTooLowException(b.getName());
    std::cout << "Bureaucrat " << b.getName()
              << " signs " << _name << " Form.\n";
    _signed = true;
}

void Form::execute(Bureaucrat const& exec) const
{
    if (_signed == false)
        throw UnsignedException();
    else if (exec.getGrade() > _execGrade)
        throw Bureaucrat::GradeTooLowException(exec.getName());
    std::cout << "Bureaucrat " << exec.getName()
              << " executes " << _name << " Form.\n";
}

/* Non-member Functions */
std::ostream& operator<<(std::ostream& out, Form const& f)
{
    out << f.getName() << " Form <s.grade " << f.getSignGrade()
        << ", ex.grade " << f.getExecGrade() << "> "
        << (f.isSigned() ? "(signed)" : "(unsigned)") << "\n";
    return out;
}

str_t titleCase(str_t s)
{
    int i = 0;
    s[i] = static_cast<char>(std::toupper(s[i]));
    while (s[i + 1]) {
        if (s[i] == ' ')
            s[i + 1] = static_cast<char>(std::toupper(s[i + 1]));
        ++i;
    }
    return s;
}

/* Exceptions */
using F_GradeHighE = Form::GradeTooHighException;
F_GradeHighE::GradeTooHighException(str_t const& whose) : _whose{ whose } {}
F_GradeHighE::~GradeTooHighException() {}
F_GradeHighE::GradeTooHighException(F_GradeHighE const& src) { *this = src; }
F_GradeHighE& F_GradeHighE::operator=(F_GradeHighE const&) { return *this; }
char const*   F_GradeHighE::what() const noexcept { return _msg.c_str(); }

using F_GradeLowE = Form::GradeTooLowException;
F_GradeLowE::GradeTooLowException(str_t const& whose) : _whose{ whose } {}
F_GradeLowE::~GradeTooLowException() {}
F_GradeLowE::GradeTooLowException(F_GradeLowE const& src) { *this = src; }
F_GradeLowE& F_GradeLowE::operator=(F_GradeLowE const&) { return *this; }
char const*  F_GradeLowE::what() const noexcept { return _msg.c_str(); }

using F_UnsignedE = Form::UnsignedException;
F_UnsignedE::UnsignedException(){}
F_UnsignedE::~UnsignedException() {}
F_UnsignedE::UnsignedException(F_UnsignedE const& src) { *this = src; }
F_UnsignedE& F_UnsignedE::operator=(F_UnsignedE const&) { return *this; }
char const*  F_UnsignedE::what() const noexcept { return _msg.c_str(); }