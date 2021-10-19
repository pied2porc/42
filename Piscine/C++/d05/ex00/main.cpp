#include "Bureaucrat.h"

Bureaucrat* createSlave(str_t const& name, int grade)
{
    try {
        return new Bureaucrat(name, grade);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << ".\n";
    }
    return nullptr;
}

int main()
{
    std::cout << "========================================\n";
    Bureaucrat* slaves[]{
        {createSlave("Nicolas", 42)},
        {createSlave("Xavier", 50)},
        {createSlave("Billy", 1)},
        {createSlave("Jimmy", -5)},
        {createSlave("Toto", 152)}
    };
    int size{ sizeof(slaves) / sizeof(*slaves) };
    for (int i = 0; i < size; ++i)
        if (slaves[i])
            std::cout << *slaves[i];
    try {
        for (int i = 0; i < 150; ++i) {
            ++(*slaves[0]);
            std::cout << *slaves[0];
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << ".\n";
    }
    return 0;
}