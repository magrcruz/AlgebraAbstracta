#ifndef Funciones_H
#define Funciones_H

#include <iostream>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace NTL;

ZZ inversa(ZZ a, ZZ b);
bool hayInversa(ZZ x,ZZ y);
bool even(ZZ a);
ZZ valAbs(ZZ a);
ZZ mcd(ZZ x,ZZ y);
ZZ mod(ZZ a,ZZ b);
ZZ aleatorio(ZZ limite=ZZ(50));
ZZ expModular(ZZ base, ZZ exp, ZZ n);
ZZ primoAleatorio();

int aleatorioint(int limite);
int modint(int a,int n);
#endif // Funciones_H
///RUTA
//"C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\Funciones.h"
