#include "RobotomyRequestForm.h"

using RRF = RobotomyRequestForm;
RRF::RobotomyRequestForm() {}
RRF::RobotomyRequestForm(str_t const& target) :
    Form(_name, target, 72, 45) {}
RRF::~RobotomyRequestForm() {}
RRF::RobotomyRequestForm(RRF const& src) { *this = src; }
RRF& RRF::operator=(RRF const& rhs)
{
    Form::operator=(rhs);
    return *this;
}

/* Member Functions */
void RRF::execute(Bureaucrat const& executor) const
{
    Form::execute(executor);
    std::cout << "VRRRRRR! VRRRRRR! ... ";
    if (std::rand() & 1)
        std::cout << getTarget() << " has been robotomized.\n";
    else
        std::cout << "Failed to robotomized " << getTarget() << ".\n";
}