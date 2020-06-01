#ifndef INVERSAMULTIPLICATIVA_H
#define INVERSAMULTIPLICATIVA_H
#include <NTL/ZZ.h>
using namespace NTL;

class InversaMultiplicativa
{
    public:
        InversaMultiplicativa();
        virtual ~InversaMultiplicativa();
        ZZ inversa(ZZ a, ZZ b);

    protected:

    private:
};

#endif // INVERSAMULTIPLICATIVA_H
