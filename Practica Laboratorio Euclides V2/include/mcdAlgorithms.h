#ifndef MCDALGORITHMS_H
#define MCDALGORITHMS_H

#include <iostream>
#include <NTL/ZZ.h>
#include <bitset>

using namespace std;
using namespace NTL;

class mcdAlgorithms
{
    public:
        static bool even(ZZ a);
        static ZZ algoritmo1(ZZ a,ZZ b);
        static ZZ algoritmo2(ZZ a,ZZ b);
        static ZZ algoritmo3(ZZ a,ZZ b);
        static ZZ algoritmo4(ZZ a,ZZ b);
        static ZZ algoritmo5(ZZ a,ZZ b);
        static ZZ algoritmo4bitwise(ZZ a,ZZ b);
        static ZZ algoritmo5bitwise(ZZ a,ZZ b);
        static ZZ algoritmo6(ZZ a,ZZ b);
        static ZZ euclidesRecursivo(ZZ a,ZZ b);
        static ZZ euclidesIterativo(ZZ a,ZZ b);
        static ZZ mods(ZZ a,ZZ b);
        static ZZ valAbs(ZZ a);


    protected:

    private:
};

#endif // MCDALGORITHMS_H
