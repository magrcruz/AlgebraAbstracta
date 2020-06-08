#ifndef MATES_H
#define MATES_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Mates
{
    public:
        static int inversa(int a, int b);
        static bool hayInversa(int x,int y);
        static bool even(int a);
        static int valAbs(int a);
        static int mcd(int x,int y);
        static int mod(int a,int b);
        static int aleatorio(int limite=RAND_MAX);
};

#endif // MATES_H
