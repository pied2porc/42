template <typename T>
void swap(T& a, T& b)
{
    T tmp{ a };
    a = b;
    b = tmp;
}

template <typename T, typename U>
auto const& min(T const& x, U const& y)
{
    return x < y ? x : y;
}

template <typename T, typename U>
auto const& max(T const& x, U const& y)
{
    return x > y ? x : y;
}

#include <iostream>
#include <string>

int main()
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    return 0;
}