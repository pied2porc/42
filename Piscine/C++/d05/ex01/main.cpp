#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main()
{
    try {
        Bureaucrat b{ "Nicolas", 42 };
        Form f1{ "subscription", 150, 1 };
        Form f2{ "tax", 30, 15 };
        
        std::cout << b;
        b.signForm(f1);
        std::cout << f1;
        b.signForm(f2);
        std::cout << f2;
    }
    catch (std::exception& e) {
        std::cerr << " because " << e.what() << ".\n";
    }

    return 0;
}