#include "Squad.h"

Squad::Squad() {}
Squad::~Squad() { destroy(); }

Squad::Squad(Squad const& src) { deepCopy(src); }
Squad& Squad::operator=(Squad const& rhs)
{
    if (this != &rhs)
        deepCopy(rhs);
    return *this;
}

/* Member Functions */
int Squad::getCount() const { return _count; }

ISpaceMarine* Squad::getUnit(int i) const
{
    if (i < 0 || ++i > _count) return nullptr;

    t_squad* ptr{ _squad };
    while (--i)
        ptr = ptr->next;
    return ptr->unit;
}

int Squad::push(ISpaceMarine* unit)
{
    if (!unit) return _count;
    
    if (!_squad) {
        _squad = new t_squad;
        _squad->unit = unit;
        return ++_count;
    }
    t_squad* member{ _squad };
    while (member->next && member->unit != unit)
        member = member->next;
    if (member->unit == unit)
        return _count;
    member->next = new t_squad;
    member->next->unit = unit;
    
    return ++_count;
}

void Squad::deepCopy(Squad const& src)
{
    destroy();
    _count = src._count;

    int i{ -1 };
    while (++i < _count)
        push(src.getUnit(i));
}

void Squad::destroy()
{
    while (_squad) {
        t_squad* toDelete{ _squad };
        _squad = _squad->next;
        delete toDelete->unit;
        delete toDelete;
    }
}