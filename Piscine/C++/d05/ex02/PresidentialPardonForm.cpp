#include "PresidentialPardonForm.h"

using PPF = PresidentialPardonForm;
PPF::PresidentialPardonForm() {}
PPF::PresidentialPardonForm(str_t const& target) :
    Form(_name, target, 25, 5) {}
PPF::~PresidentialPardonForm() {}
PPF::PresidentialPardonForm(PPF const& src) { *this = src; }
PPF& PPF::operator=(PPF const& rhs)
{
    Form::operator=(rhs);
    return *this;
}

/* Member Functions */
void PPF::execute(Bureaucrat const& executor) const
{
    Form::execute(executor);
    std::cout << getTarget()
              << " has been pardoned by Zafod Beeblebrox.\n";
}