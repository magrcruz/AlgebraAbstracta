#ifndef RAILFENCE_H
#define RAILFENCE_H
#include <string>
#include <iostream>
using namespace std;

class RailFence
{
    public:
        RailFence(int clave=2);
        string cifrado(string mensaje);
        string descifrado(string mensajeCifrado);
    protected:

    private:
        int clave;
};

#endif // RAILFENCE_H
