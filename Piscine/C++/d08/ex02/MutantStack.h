#pragma once
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    ~MutantStack() {}
    MutantStack(MutantStack const& src) : std::stack<T>(src) {}
    using std::stack<T>::operator=;

    using iterator = typename std::stack<T>::container_type::iterator;
    auto begin();
    auto end();
    using const_iterator = typename std::stack<T>::container_type::const_iterator;
    auto begin() const;
    auto end() const;
};

template <typename T>
//typename MutantStack<T>::iterator
auto MutantStack<T>::begin() { return std::stack<T>::c.begin(); }

template <typename T>
//typename MutantStack<T>::iterator
auto MutantStack<T>::end() { return std::stack<T>::c.end(); }

template <typename T>
//typename MutantStack<T>::const_iterator
auto MutantStack<T>::begin() const { return std::stack<T>::c.begin(); }

template <typename T>
//typename MutantStack<T>::const_iterator
auto MutantStack<T>::end() const { return std::stack<T>::c.end(); }