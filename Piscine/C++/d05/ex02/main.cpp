#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    std::cout << "====================================\n";
    Bureaucrat n{ "Nicolas", 42 };
    Bureaucrat x{ "Xavier", 142 };
    Bureaucrat b{ "Noob", 150 };
    ShrubberyCreationForm shrub{ "Bush" };
    RobotomyRequestForm robo{ "Xavier" };
    PresidentialPardonForm pardon{"Xavier"};
    

    std::cout << n << x << b;
    std::cout << shrub << robo << pardon << "\n";

    n.executeForm(shrub);
    x.executeForm(shrub);
    b.signForm(shrub);
    x.signForm(shrub);
    x.executeForm(shrub);
    n.executeForm(shrub);
    std::cout << "\n";

    n.signForm(robo);
    n.executeForm(robo);
    std::cout << "\n";

    x.executeForm(pardon);
    x.signForm(pardon);
    for (int i{ 0 }; i < 140; ++i, ++x);
    std::cout << x;
    x.signForm(pardon);
    x.executeForm(pardon);
    std::cout << shrub << robo << pardon << "\n";

    return 0;
}