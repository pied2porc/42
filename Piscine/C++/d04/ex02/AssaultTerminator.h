#pragma once
#include "ISpaceMarine.h"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    ~AssaultTerminator();
    
    AssaultTerminator(AssaultTerminator const&);
    AssaultTerminator& operator=(AssaultTerminator const&);

    ISpaceMarine*  clone() const;
    void           battleCry() const;
    void           rangedAttack() const;
    void           meleeAttack() const;
};