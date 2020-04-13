#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include <string>
using namespace std;

class Cesar
{
    public:
        Cesar();
        Cesar(int clave,string alfabeto);
        string cifrado(string mensaje);
        string descifrado(string mensajeCifrado);

        string alfabeto;

    protected:

    private:
        int clave;

};

#endif // CESAR_H
