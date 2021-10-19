#include "Instruction.h"
#include <exception>
#include <iostream>

/* > */
MoveRight::MoveRight() {}
MoveRight::~MoveRight() {}
MoveRight::MoveRight(MoveRight const& src) { *this = src; }
MoveRight& MoveRight::operator=(MoveRight const&) { return *this; }

char const MoveRight::getName() const { return _name; }
void       MoveRight::execute(std::string::iterator& it,
                              std::vector<Instruction*> const&,
                              std::vector<Instruction*>::iterator&) { ++it; }

/* < */
MoveLeft::MoveLeft() {}
MoveLeft::~MoveLeft() {}
MoveLeft::MoveLeft(MoveLeft const& src) { *this = src; }
MoveLeft& MoveLeft::operator=(MoveLeft const&) { return *this; }

char const MoveLeft::getName() const { return _name; }
void       MoveLeft::execute(std::string::iterator& it,
                             std::vector<Instruction*> const&,
                             std::vector<Instruction*>::iterator&) { --it; }

/* + */
Increment::Increment() {}
Increment::~Increment() {}
Increment::Increment(Increment const& src) { *this = src; }
Increment& Increment::operator=(Increment const&) { return *this; }

char const Increment::getName() const { return _name; }
void       Increment::execute(std::string::iterator& it,
                              std::vector<Instruction*> const&,
                              std::vector<Instruction*>::iterator&) { ++*it; }

/* - */
Decrement::Decrement() {}
Decrement::~Decrement() {}
Decrement::Decrement(Decrement const& src) { *this = src; }
Decrement& Decrement::operator=(Decrement const&) { return *this; }

char const Decrement::getName() const { return _name; }
void       Decrement::execute(std::string::iterator& it,
                              std::vector<Instruction*> const&,
                              std::vector<Instruction*>::iterator&) { --*it; }

/* . */
Output::Output() {}
Output::~Output() {}
Output::Output(Output const& src) { *this = src; }
Output& Output::operator=(Output const&) { return *this; }

char const Output::getName() const { return _name; }
void       Output::execute(std::string::iterator& it,
                           std::vector<Instruction*> const&,
                           std::vector<Instruction*>::iterator&) { std::cout << *it; }

/* , */
Input::Input() {}
Input::~Input() {}
Input::Input(Input const& src) { *this = src; }
Input& Input::operator=(Input const&) { return *this; }

char const Input::getName() const { return _name; }
void       Input::execute(std::string::iterator& it,
                          std::vector<Instruction*> const&,
                          std::vector<Instruction*>::iterator&) { std::cin.get(*it); }

/* [ */
JumpForward::JumpForward() {}
JumpForward::~JumpForward() {}
JumpForward::JumpForward(JumpForward const& src) { *this = src; }
JumpForward& JumpForward::operator=(JumpForward const&) { return *this; }

char const JumpForward::getName() const { return _name; }
void       JumpForward::execute(std::string::iterator& it,
                                std::vector<Instruction*> const& cmds,
                                std::vector<Instruction*>::iterator& cmd)
{
    if (*it) return;

    int brackets{ 1 };
    auto end{ cmds.end() };
    while (brackets && ++cmd != end) {
        if ((*cmd)->getName() == '[')
            ++brackets;
        else if ((*cmd)->getName() == ']')
            --brackets;
    }
    if (brackets)
        throw std::logic_error("missing close bracket");
}

/* ] */
JumpBackward::JumpBackward() {}
JumpBackward::~JumpBackward() {}
JumpBackward::JumpBackward(JumpBackward const& src) { *this = src; }
JumpBackward& JumpBackward::operator=(JumpBackward const&) { return *this; }

char const JumpBackward::getName() const { return _name; }
void       JumpBackward::execute(std::string::iterator& it,
                                 std::vector<Instruction*> const& cmds,
                                 std::vector<Instruction*>::iterator& cmd)
{
    if (!*it) return;
    
    int brackets{ 1 };
    auto begin{ cmds.begin() };
    while (brackets && --cmd != begin) {
        if ((*cmd)->getName() == ']')
            ++brackets;
        else if ((*cmd)->getName() == '[')
            --brackets;
    }
    if (brackets)
        throw std::logic_error("missing open bracket");
}