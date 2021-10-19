#include "Intern.h"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Form* rrf;
    Form* ppf;
    Form* scf;
    Form* inv;
    
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        ppf = someRandomIntern.makeForm("presidential pardon", "Nicolas");
        scf = someRandomIntern.makeForm("shrubbery creation", "Xavier");
        inv = someRandomIntern.makeForm("pay raise", "Boss");
    }
    catch (std::exception& e) {
        std::cout << e.what() << ".\n";
    }

    return 0;
}