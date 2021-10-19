#pragma once
#include "Instruction.h"
#include <fstream>
#include <string>
#include <vector>

class Instruction;

class Mindopen
{
private:
    static constexpr size_t             _size{ 30000 };
    std::string                         _memory;
    std::string::iterator               _memIt{ _memory.begin() };
    std::vector<Instruction*>           _cmds;

public:
    Mindopen();
    ~Mindopen();
    Mindopen(Mindopen const&) = delete;
    Mindopen& operator=(Mindopen const&) = delete;

    std::string::iterator& getMemIt();

    void queue(std::ifstream&);
    void execute();
};