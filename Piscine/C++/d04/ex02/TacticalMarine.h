#pragma once
#include "ISpaceMarine.h"

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine();
    ~TacticalMarine();

    TacticalMarine(TacticalMarine const&);
    TacticalMarine& operator=(TacticalMarine const&);

    ISpaceMarine*  clone() const;
    void           battleCry() const;
    void           rangedAttack() const;
    void           meleeAttack() const;
};