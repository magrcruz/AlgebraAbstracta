#ifndef INVERSAM_H
#define INVERSAM_H
#include <iostream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class InversaM
{
    public:
        ZZ inversa(ZZ a, ZZ b);

        bool hayInversa(ZZ x,ZZ y);
        bool even(ZZ a);
        ZZ valAbs(ZZ a);
        ZZ mcd(ZZ x,ZZ y);
        ZZ mod(ZZ a,ZZ b);

    protected:

    private:
};

#endif // INVERSAM_H
