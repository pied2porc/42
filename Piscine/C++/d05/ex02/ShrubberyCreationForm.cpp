#include "ShrubberyCreationForm.h"
#include <fstream>

using SCF = ShrubberyCreationForm;
SCF::ShrubberyCreationForm() {}
SCF::ShrubberyCreationForm(str_t const& target) :
    Form(_name, target, 145, 137) {}
SCF::~ShrubberyCreationForm() {}
SCF::ShrubberyCreationForm(SCF const& src) { *this = src; }
SCF& SCF::operator=(SCF const& rhs)
{
    Form::operator=(rhs);
    return *this;
}

/* Member Functions */
void SCF::execute(Bureaucrat const& executor) const
{
    Form::execute(executor);
    str_t const filename{ getTarget() + "_shrubbery" };
    std::ofstream ofs(filename);
    ofs << "    ____\n"
        << "  _(    )__\n"
        << " (         )\n"
        << "(_         _)\n"
        << " (___, ;___)\n"
        << "     j |\n"
        << "     \\ |\n"
        << "  ,__j l_,,_\n";
}