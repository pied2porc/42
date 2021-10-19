#pragma once
#include "Form.h"

class RobotomyRequestForm : public Form
{   
public:
    static inline const str_t _name{ "robotomy request" };
    
    RobotomyRequestForm();
    RobotomyRequestForm(str_t const&);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const&);
    RobotomyRequestForm& operator=(RobotomyRequestForm const&);

    void execute(Bureaucrat const&) const;
};