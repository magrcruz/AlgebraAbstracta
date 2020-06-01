#ifndef MONOMIOBINOMIO_H
#define MONOMIOBINOMIO_H
#include <string>
#include <iostream>
using namespace std;

class MonomioBinomio
{
    public:
        MonomioBinomio(string claves="27",string keyword="DENARIOS");
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        int mod_positive(int a,int n);
        string alfabeto;
    protected:

    private:
        string keyword;
        string claves;
        string tablero;
};

#endif // MONOMIOBINOMIO_H
