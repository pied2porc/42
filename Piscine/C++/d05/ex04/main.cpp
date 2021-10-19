#include "Bureaucrat.h"
#include "Intern.h"
#include "OfficeBlock.h"
#include <iostream>

int main()
{
    Intern      idiotOne;
    Bureaucrat  hermes{ Bureaucrat{"Hermes Conrad", 37} };
    Bureaucrat  bob{ Bureaucrat{"Bobby Bobson", 123} };
    OfficeBlock ob;

    ob.setIntern(idiotOne);
    ob.setSigner(bob);
    ob.setExecutor(hermes);
    try {
        //ob.doBureaucracy("pay raise", "Pigley");
        //ob.doBureaucracy("presidential pardon", "Pigley");
        //ob.doBureaucracy("robotomy request", "Pigley");
        ob.doBureaucracy("shrubbery creation", "Pigley");
    }
    catch (OfficeBlock::MissingInternException& e) {
        std::cout << e.what() << ".\n";
    }
    catch (OfficeBlock::MissingSignerException& e) {
        std::cout << e.what() << ".\n";
    }
    catch (OfficeBlock::MissingExecutorException& e) {
        std::cout << e.what() << ".\n";
    }
    catch (Form::UnsignedException& e) {
        std::cout << e.what() << ".\n";
    }
    catch (Intern::UnknownFormException& e) {
        std::cout << e.what() << ".\n";
    }
    catch (Bureaucrat::SignException& e) {
        std::cout << " because " << e.what() << ".\n";
    }
    catch (Bureaucrat::ExecuteException& e) {
        std::cout << " because " << e.what() << ".\n";
    }
    catch (std::exception& e) {
        std::cout << "Unkown error: " << e.what() << ".\n";
    }
    return EXIT_SUCCESS;
}