#pragma once
#include <string>

#define CALL_MBR_FN(obj, ptr)   ((obj).*(ptr))

class Human
{
    void meleeAttack(std::string const&);
    void rangedAttack(std::string const&);
    void intimidatingShout(std::string const&);

public:
    void action(std::string const&, std::string const&);
};