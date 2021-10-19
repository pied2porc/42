#pragma once
#include <string>

using str_t = std::string;

class Enemy
{
protected:
    str_t   _type{ "???" };
    int     _hp{ 0 };

public:
    Enemy();
    Enemy(int, str_t const&);
    virtual ~Enemy();

    Enemy(Enemy const&);
    Enemy& operator=(Enemy const&);

    str_t const& getType() const;
    int          getHP() const;

    virtual void takeDamage(int);
};