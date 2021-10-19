#pragma once
#include "ISquad.h"

class Squad : public ISquad
{
private:
    int      _count{ 0 };
    typedef struct s_squad {
        ISpaceMarine*   unit{ nullptr };
        struct s_squad* next{ nullptr };
    } t_squad;
    t_squad* _squad{ nullptr };

public:
    Squad();
    ~Squad();

    Squad(Squad const&);
    Squad& operator=(Squad const&);

    int           getCount() const;
    ISpaceMarine* getUnit(int) const;

    int           push(ISpaceMarine*);
    void          deepCopy(Squad const&);
    void          destroy();
};