#pragma once
#include "Form.h"

class PresidentialPardonForm : public Form
{
public:
    static inline const str_t _name{ "presidential pardon" };

    PresidentialPardonForm();
    PresidentialPardonForm(str_t const&);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const&);
    PresidentialPardonForm& operator=(PresidentialPardonForm const&);

    void execute(Bureaucrat const&) const;
};