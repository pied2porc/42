#pragma once
#include "Bureaucrat.h"
#include "Intern.h"
#include "OfficeBlock.h"
#include <string>

using str_t = std::string;

class CentralBureaucracy
{
private:
    static unsigned int constexpr _maxBlock{ 20 };
    OfficeBlock  _blocks[_maxBlock];
    Intern       _intern;
    unsigned int _slavesCount{ 0 };

    typedef struct s_queue {
        str_t           name;
        struct s_queue* next{ nullptr };
    } t_queue;

    t_queue*    _head{ nullptr };
    t_queue*    _tail{ nullptr };

public:
    CentralBureaucracy();
    ~CentralBureaucracy();
    CentralBureaucracy(CentralBureaucracy const&);
    CentralBureaucracy& operator=(CentralBureaucracy const&);

    void feed(Bureaucrat*);
    void queueUp(str_t const&);
    void dequeue();
    void doBureaucracy();
};