#ifndef VIGENERECLASS_H
#define VIGENERECLASS_H
#include <iostream>
#include <string>

using namespace std;

class VigenereClass
{
    public:
        VigenereClass();
        VigenereClass(string clave);
        virtual ~VigenereClass();
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        //void setClave(string clave);
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    protected:

    private:
        string clave="Pablo Neruda";
};

#endif // VIGENERECLASS_H
