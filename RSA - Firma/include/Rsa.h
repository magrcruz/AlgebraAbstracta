#ifndef RSA_H
#define RSA_H
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\funciones.h"
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\numeroAleatorio.h"
using namespace std;
using namespace NTL;

class Rsa
{
    public:
        Rsa(int bits);
        Rsa(ZZ n,ZZ e);
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
        string cifrado(string mensaje,ZZ Nr,ZZ Er);
        string descifrado(string mensaje);
        string dividirBloques(string mensaje);
        string completarCeros(string mensaje,ZZ Nr);
        string ZZtoStr(ZZ z);
        string cifroConD(string mensajeNo);
        string descifroConE(string mensajeNo,ZZ Ne,ZZ Ee);
        string firmarYCifrar(string mensajeL,ZZ Nr,ZZ Er);
        string defirmar(string mensaje,ZZ Ne,ZZ Ee);
        ZZ n, e;
    private:
        ZZ d, fiN, p, q;
        ZZ Trc(ZZ M);
};

#endif // RSA_H


