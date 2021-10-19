#include "Instruction.h"
#include "Mindopen.h"
#include <exception>
#include <iostream>
#include <iterator>

Mindopen::Mindopen() : _memory(_size, '\0') {}
Mindopen::~Mindopen() { for (auto& cmd : _cmds) delete cmd; }

std::string::iterator& Mindopen::getMemIt() { return _memIt; }

void Mindopen::queue(std::ifstream& ifs)
{
    while (ifs) {
        char c{ static_cast<char>(ifs.get()) };
        switch (c) {
        case '>': _cmds.push_back(new MoveRight); break;
        case '<': _cmds.push_back(new MoveLeft); break;
        case '+': _cmds.push_back(new Increment); break;
        case '-': _cmds.push_back(new Decrement); break;
        case '.': _cmds.push_back(new Output); break;
        case ',': _cmds.push_back(new Input); break;
        case '[': _cmds.push_back(new JumpForward); break;
        case ']': _cmds.push_back(new JumpBackward); break;
        }
    }
}

void Mindopen::execute()
{
    auto end{ _cmds.cend() };
    auto cmd{ _cmds.begin() };
    try {
        while (cmd != end) {
            //std::cout << (*cmd)->getName();
            (*cmd)->execute(getMemIt(), _cmds, cmd);
            ++cmd;
        }
    }
    catch (std::logic_error const& e) {
        std::cerr << "\nSyntax error: " << e.what() << '\n';
    }
}