#include "Zombie.h"
#include "ZombieEvent.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return (min + static_cast<int>(std::rand() * fraction * (max - min + 1)));
}

void randomChump()
{
    static str_t names[]{ "John", "Homer", "Clair", "Peter" };
    int          size{ sizeof names / sizeof * names };
    str_t const& name{ names[getRandomNumber(0, size - 1)] };
    str_t const& msg{
        (name == "Homer" ? "Mmmm...donuts..." : "Braiiiiiiinnnssss...") };

    Zombie z{ name, "chump" };
    z.announce(msg);
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand(); // discard the first number
    std::cout << "------------------------------------\n";

    ZombieEvent ze;
    ze.setZombieType("42");
    Zombie* xavier{ ze.newZombie("Xavier") };
    Zombie* nicolas{ ze.newZombie("Nicolas") };
    nicolas->announce("Hello World!");
    xavier->announce("Il a Free, il a tout compris.");
    delete nicolas;
    delete xavier;

    randomChump();
    randomChump();
    randomChump();

    return 0;
}