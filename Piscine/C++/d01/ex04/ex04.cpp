#include <iostream>

int main()
{
    std::string  s{ "HI THIS IS BRAIN" };
    std::string* s_ptr{ &s };
    std::string& s_ref{ s };

    std::cout << *s_ptr << "\n";
    std::cout << s_ref << "\n";
    return 0;
}