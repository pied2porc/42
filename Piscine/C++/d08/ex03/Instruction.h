#pragma once
#include "Mindopen.h"
#include <string>
#include <vector>

class Instruction
{
public:
    virtual ~Instruction() {}

    virtual char const getName() const = 0;
    virtual void       execute(std::string::iterator&,
                               std::vector<Instruction*> const&,
                               std::vector<Instruction*>::iterator&) = 0;
};

class MoveRight : public Instruction
{
    char const _name{ '>' };

public:
    MoveRight();
    ~MoveRight();
    MoveRight(MoveRight const&);
    MoveRight& operator=(MoveRight const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class MoveLeft : public Instruction
{
    char const _name{ '<' };

public:
    MoveLeft();
    ~MoveLeft();
    MoveLeft(MoveLeft const&);
    MoveLeft& operator=(MoveLeft const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class Increment : public Instruction
{
    char const _name{ '+' };

public:
    Increment();
    ~Increment();
    Increment(Increment const&);
    Increment& operator=(Increment const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class Decrement : public Instruction
{
    char const _name{ '-' };
    
public:
    Decrement();
    ~Decrement();
    Decrement(Decrement const&);
    Decrement& operator=(Decrement const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class Output : public Instruction
{
    char const _name{ '.' };

public:
    Output();
    ~Output();
    Output(Output const&);
    Output& operator=(Output const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class Input : public Instruction
{
    char const _name{ ',' };

public:
    Input();
    ~Input();
    Input(Input const&);
    Input& operator=(Input const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class JumpForward : public Instruction
{
    char const _name{ '[' };

public:
    JumpForward();
    ~JumpForward();
    JumpForward(JumpForward const&);
    JumpForward& operator=(JumpForward const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};

class JumpBackward : public Instruction
{
    char const _name{ ']' };

public:
    JumpBackward();
    ~JumpBackward();
    JumpBackward(JumpBackward const&);
    JumpBackward& operator=(JumpBackward const&);

    char const getName() const;
    void       execute(std::string::iterator&,
                       std::vector<Instruction*> const&,
                       std::vector<Instruction*>::iterator&);
};