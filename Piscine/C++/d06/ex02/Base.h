#pragma once

class Base
{
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void  identify_from_pointer(Base*);
void  identify_from_reference(Base&);