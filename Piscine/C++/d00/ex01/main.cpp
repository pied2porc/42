#include "Contact.h"
#include "Phonebook.h"
#include "utils.h"
#include <iostream>
#include <string>

int main()
{
    Phonebook book;
    std::string input;

    while (input != "exit") {
        std::cout << "Enter a command (add, search, exit)> ";
        std::getline(std::cin, input);
        
        if (input == "add") {
            if (book.isFull())
                std::cout << "Your phone book is full.\n";
            else
                book.add_contact();
        }
        else if (input == "search") {
            if (book.isEmpty())
                std::cout << "You have 0 contact.\n";
            else {
                book.print();
                if (Contact* contact = book.search_contact())
                    contact->print();
            }
        }
    }
    return 0;
}