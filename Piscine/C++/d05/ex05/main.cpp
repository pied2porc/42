#include "Bureaucrat.h"
#include "CentralBureaucracy.h"
#include <ctime>
#include <string>

using str_t = std::string;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    auto rng{ [](int min, int max) {
        return (min + static_cast<int>(std::rand() * fraction * (max - min + 1)));}
    };
    static const str_t names[]{
        "Ai", "Aina", "Aika", "Arisa", "Anju",
        "Anne", "Aurore", "Ben", "Billy", "Chika",
        "Claire", "Dia", "David", "Elisa", "Francois",
        "Greg", "Hanamaru", "Hubert", "John", "Jenifer",
        "Karine", "Kanako", "Kanan", "Laura", "Marie",
        "Nanaka", "Nicolas", "Olivier", "Paul", "Quentin",
        "Riko", "Rikako", "Robert", "Rose", "Ruby",
        "Rumiko", "Shuka", "Sylvain", "Sylvie", "Sophie",
        "Steve", "Tristan", "Umi", "Veronique", "Vincent",
        "Wen", "Xi", "You", "Yoshiko", "Zhen"
    };
    
    CentralBureaucracy  center;
    int constexpr max_names{ sizeof(names) / sizeof(*names) };
    int constexpr max_slaves{ 40 };

    for (int i{ 0 }; i < max_slaves; ++i) {
        str_t name{ names[rng(0, max_names - 1)] };
        int grade{ rng(1, 150) };
        center.feed(new Bureaucrat(name, grade));
    }
    for (int i{ 0 }; i < max_names; ++i)
        center.queueUp(names[rng(0, max_names - 1)]);

    std::cout << "========================================"
              << "========================================\n";
    center.doBureaucracy();

    return 0;
}