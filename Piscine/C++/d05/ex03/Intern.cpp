#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

inline const Intern::t_form Intern::_forms[]{
    {PresidentialPardonForm::_name, &Intern::makePPF},
    {RobotomyRequestForm::_name, &Intern::makeRRF},
    {ShrubberyCreationForm::_name, &Intern::makeSCF}
};

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const& src) { *this = src; }
Intern& Intern::operator=(Intern const&) { return *this; }

Form* Intern::makeForm(str_t const& name, str_t const& target) const
{
    for (auto& f : _forms)
        if (f.name == name) {
            Form* form{ (this->*f.mfn)(target) };
            std::cout << "Intern creates " << *form
                      << " targeted on " << target << ".\n";
            return form;
        }
    throw UnknownFormException(name);
}

Form* Intern::makePPF(str_t const& target) const { return new PresidentialPardonForm{ target }; }
Form* Intern::makeRRF(str_t const& target) const { return new RobotomyRequestForm{ target }; }
Form* Intern::makeSCF(str_t const& target) const { return new ShrubberyCreationForm{ target }; }

/* Exceptions */
using I_UnknownE = Intern::UnknownFormException;
I_UnknownE::UnknownFormException(str_t const& name) : _name{ name } {}
I_UnknownE::~UnknownFormException() {}
I_UnknownE::UnknownFormException(UnknownFormException const& src) { *this = src; }
I_UnknownE& I_UnknownE::operator=(UnknownFormException const&) { return *this; }
char const* I_UnknownE::what() const noexcept { return _msg.c_str(); }