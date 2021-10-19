#pragma once

class IAsteroid;

class IMiningLaser
{
public:
    virtual ~IMiningLaser() {}

    virtual void mine(IAsteroid*) = 0;
};