#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\MathZZ.h"

using namespace std;
using namespace NTL;

class Rsa
{
    public:
        Rsa();
        Rsa(ZZ n,ZZ e);
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        void cifrado(string mensaje);
        void cifrado();
        void descifrado();

        void numbersLetters();
        ZZ n,e;
    private:
        ZZ d;
};

#endif // RSA_H
