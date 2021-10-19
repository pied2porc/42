#include "Brain.h"
#include <iostream>
#include <sstream>

Brain::Brain()
{
    std::ostringstream address;
    address << this;
    m_address = "0x" + address.str();
}

const str_t& Brain::identify() const { return m_address; }