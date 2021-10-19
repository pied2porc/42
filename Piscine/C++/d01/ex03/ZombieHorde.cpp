#include "ZombieHorde.h"

ZombieHorde::ZombieHorde(std::size_t n) : m_size{ n }
{
    static const str_t names[]{ "Peter", "Homer", "Clair", "John" };
    static constexpr int size{ sizeof names / sizeof * names };
    m_horde = new Zombie[n]{};
    for (size_t i{ 0 }; i < n; ++i) {
        m_horde[i].set_name(names[getRandomNumber(0, size - 1)]);
        m_horde[i].set_type("horde");
    }
}

ZombieHorde::~ZombieHorde()
{
    delete[] m_horde;
}

void ZombieHorde::announce()
{
    for (size_t i{ 0 }; i < m_size; ++i) {
        if (m_horde[i].get_name() == "Homer")
            m_horde[i].announce("Mmmm...donuts...");
        else
            m_horde[i].announce("Braiiiiiiinnnssss...");
    }
}