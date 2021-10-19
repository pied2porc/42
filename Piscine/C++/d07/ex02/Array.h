#pragma once
#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
    size_t  _size{ 1 };
    T*      _array{};

public:
    Array();
    Array(size_t);
    ~Array();
    Array(Array const&);
    Array& operator=(Array const&);

    T&     operator[](size_t);

    size_t size() const;
};

template <typename T>
Array<T>::Array() : _array{ new T[1]{} } {}

template <typename T>
Array<T>::Array(size_t size) : _array{ new T[size]{} }, _size{ size } {}

template <typename T>
Array<T>::~Array() { delete[] _array; }

template <typename T>
Array<T>::Array(Array<T> const& src) { *this = src; }

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& rhs)
{
    if (this == &rhs) return *this;
    if (_size != rhs._size) {
        delete[] _array;
        _size = rhs._size;
        _array = new T[_size];
    }
    
    for (size_t i{ 0 }; i < _size; ++i)
        _array[i] = rhs._array[i];
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t pos)
{
    if (!(pos < _size))
        throw std::out_of_range("index is out of range");
    return _array[pos];
};

template <typename T>
size_t Array<T>::size() const { return _size; }