#ifndef POLYBIOSCIPHER_H
#define POLYBIOSCIPHER_H
#include <iostream>
#include <string>

using namespace std;

class polybiosCipher
{
    public:
        polybiosCipher();

        static string cifrado(string mensaje);
        static string descifrado(string mensajeCifrado);

        static string alfabeto;
    protected:

    private:
};

#endif // POLYBIOSCIPHER_H
