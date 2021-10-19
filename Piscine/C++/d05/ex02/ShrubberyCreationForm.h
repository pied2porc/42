#pragma once
#include "Form.h"

class ShrubberyCreationForm : public Form
{
public:
    static inline const str_t _name{ "shrubbery creation" };
    
    ShrubberyCreationForm();
    ShrubberyCreationForm(str_t const&);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const&);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const&);

    void execute(Bureaucrat const&) const;
};