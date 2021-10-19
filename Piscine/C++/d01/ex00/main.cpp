#include "Pony.h"
#include <iostream>

void ponyOnTheHeap()
{
    Pony* pony{ new Pony("Johnny", 3) };
    pony->talk("I'm a fat pony.");
    delete pony;
}

void ponyOnTheStack()
{
    Pony pony("Berta", 2);
    pony.talk("I'm a healthy pony!");
}

int main()
{
    ponyOnTheHeap();
    ponyOnTheStack();

    std::cout << "This...does put a smile on my face.";
    return 0;
}