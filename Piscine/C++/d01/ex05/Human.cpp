#include "Human.h"
#include "Brain.h"
#include <iostream>

Human::~Human()
{
    delete m_brain;
    std::cout << "Brain's dead.";
}

Brain const& Human::getBrain() const { return *m_brain; }
str_t const& Human::identify() const { return m_brain->identify(); }