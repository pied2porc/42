#include "Fixed.h"
#include <cmath>
#include <cstdint>
#include <iostream>

int      constexpr binaryPt         { 8 };
uint32_t constexpr fractionMask     { 0xffffffff >> (32 - binaryPt) };

inline float FixedToFloat(int   x)  { return ((float)x / (1 << binaryPt)); }
inline int   FloatToFixed(float x)  { return (int)roundf(x * (1 << binaryPt)); }
inline int   IntToFixed(int x)      { return x << binaryPt; }
inline int   FixedToInt(int x)      { return x >> binaryPt; }

inline float FractionPart(int x)    { return FixedToFloat(x & fractionMask); }
inline int   WholePart(int x)       { return FixedToInt(x); }
inline int   Mul(int x, int y)      { return (x * y) >> binaryPt; }
inline int   Div(int x, int y)      { return (x << binaryPt) / y; }

int main()
{
    using fixed_t = int;
    std::cout.precision(4);

    fixed_t f1{ FloatToFixed(7.1f) };
    fixed_t f2{ IntToFixed(3) };
    
    std::cout << "float: " << FixedToFloat(f1)
              << " (frac: " << FractionPart(f1)
              << " whole: " << WholePart(f1) << ")"
              << " int: " << FixedToInt(f2) << "\n";
        

    std::cout << "Sum: " << FixedToFloat(f1 + f2) << "\n";
    std::cout << "Sub: " << FixedToFloat(f1 - f2) << "\n";
    std::cout << "Mul: " << FixedToFloat(Mul(f1, f2)) << "\n";

    f1 = FloatToFixed(2.8f);
    f2 = FloatToFixed(3.6f);
    std::cout << "float: " << FixedToFloat(f1)
              << " float: " << FixedToFloat(f2) << "\n";
    std::cout << "Div: " << FixedToFloat(Div(f1, f2)) << "\n";
    std::cout << "\n";

    std::cout << "0.4+2.8= " << Fixed(0.4f) + Fixed(2.8f) << "\n";
    std::cout << "2.6-5.8= " << Fixed(2.6f) - Fixed(5.8f) << "\n";
    std::cout << "1.2*3.7= " << Fixed(1.2f) * Fixed(3.7f) << "\n";
    std::cout << "1.0/3.0= " << Fixed(1.0f) / Fixed(3.0f) << "\n";

    return 0;
}