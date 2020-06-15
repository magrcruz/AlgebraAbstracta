#ifndef MathZZ_H
#define MathZZ_H

#include <iostream>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace NTL;

class MathZZ
{
    public:
        static ZZ inversa(ZZ a, ZZ b);
        static bool hayInversa(ZZ x,ZZ y);
        static bool even(ZZ a);
        static ZZ valAbs(ZZ a);
        static ZZ mcd(ZZ x,ZZ y);
        static ZZ mod(ZZ a,ZZ b);
        static ZZ aleatorio(ZZ limite=ZZ(50));
        static ZZ expModular(ZZ base, ZZ exp, ZZ n);
        static ZZ primoAleatorio();
};

#endif // MathZZ_H
///RUTA
//"C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\MathZZ.h"
