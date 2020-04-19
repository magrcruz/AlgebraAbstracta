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
        void setClave(string clave);
        string alfabeto;
    protected:

    private:
        string clave;
};

#endif // VIGENERECLASS_H

//profesora, el enlace del repositorio lo envié con el anterior trabajo entonces solo actualice el repositorio, ¿debería enviarlo de nuevo?
