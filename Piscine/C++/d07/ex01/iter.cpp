#include <iostream>
#include <string>

template <typename T>
void iter(T* array, size_t len, void (*fn)(T const&))
{
    for (size_t i{ 0 }; i < len; ++i)
        fn(array[i]);
}

template <typename T>
void print(T const& elem)
{
    std::cout << elem << ' ';
}

int main()
{
    int         iarray[]{ 1, 2 ,3 ,4 ,5 };
    std::string sarray[]{ "titi", "tata", "toto", "tutu" };

    iter(iarray, 5, print);
    std::cout << '\n';
    iter(sarray, 4, print);

    return 0;
}