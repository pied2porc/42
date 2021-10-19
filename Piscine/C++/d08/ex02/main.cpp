#include "MutantStack.h"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "mstack.top(): " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "mstack.size(): " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "while loop: ";
    while (it != ite) {
        std::cout << *it << ' ';
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\nforeach loop: ";
    for (auto e : mstack)
        std::cout << e << ' ';

    std::cout << "\nstack.size(): ";
    std::cout << s.size();

    return 0;
}