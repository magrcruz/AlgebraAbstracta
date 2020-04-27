#ifndef VIGENEREASCII_H
#define VIGENEREASCII_H

#include <iostream>
#include <string>

using namespace std;

class VigenereAscii
{
    public:
        VigenereAscii();
        VigenereAscii(string clave);
        virtual ~VigenereAscii();
        string cifrado(string mensaje);
        string descifrado(string mensaje);

        string cifradoModified(string mensaje);
        string descifradoModified(string mensaje);
        void setClave(string clave);
        void setAlfabeto(string alf,int ini,int fin);
        string alfabeto;
    protected:

    private:
        string clave="Pablo Neruda";
        string claveAux;
        size_t inicoAlfabeto;
        size_t finAlfabeto;
};
#endif // VIGENEREASCII_H
