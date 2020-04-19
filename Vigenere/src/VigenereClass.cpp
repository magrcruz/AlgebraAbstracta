#include "VigenereClass.h"

VigenereClass::VigenereClass(){
    clave="ctyvgubhinj";
    alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
}
VigenereClass::VigenereClass(string clave){
    this->clave=clave;
    alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
}

VigenereClass::~VigenereClass()
{
    //dtor
}

//alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRS,.";
string VigenereClass::cifrado(string mensaje){
    string salida;
    size_t a,b;
    int suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.find(clave.at(i%clave.size()));
        b=alfabeto.find(mensaje.at(i));
        if(a==string::npos || b==string::npos)
            salida+=mensaje.at(i);
        else{
            suma=a+b;
            if (suma>=alfabeto.size()) suma%=alfabeto.size();
            salida+=alfabeto.at(suma);
        }
    }
    return salida;
}

string VigenereClass::descifrado(string mensaje){
    string salida;
    size_t a,b;
    int resta=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.find(mensaje.at(i));
        b=alfabeto.find(clave.at(i%clave.size()));
        resta=a-b;
        if(a==string::npos || b==string::npos)
            salida+=mensaje.at(i);
        else{
            if (resta<0) resta+=alfabeto.size();
            else if (resta>=alfabeto.size()) resta%=alfabeto.size();
            salida+=alfabeto.at(resta);
        }
    }
    return salida;
//al texto cifrado se le resta la letra
}

void VigenereClass::setClave(string clave){this->clave=clave;}
