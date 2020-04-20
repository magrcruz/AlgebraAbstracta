#include "VigenereClass.h"

VigenereClass::VigenereClass(){
    clave="Pablo Neruda";
    alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";

}
VigenereClass::VigenereClass(string clave){
    if(clave=="") clave="clave";
    else this->clave=clave;
    alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
}

VigenereClass::~VigenereClass()
{
    //dtor
}

string VigenereClass::cifrado(string mensaje){
    string salida;
    int a,b,suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.find(clave.at(i%clave.size()));
        b=alfabeto.find(mensaje.at(i));
        if (a!=string::npos&&b!=string::npos){
            suma=a+b;
            if (suma>=alfabeto.size()) suma%=alfabeto.size();
            salida+=alfabeto.at(suma);
        }
        else salida+=mensaje.at(i);
    }
    return salida;
}




string VigenereClass::descifrado(string mensaje){
    string salida;
    int a,b,resta=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.find(mensaje.at(i));
        b=alfabeto.find(clave.at(i%clave.size()));
        if(a!=string::npos&&b!=string::npos){
            resta=a-b;
            if (resta<0) resta+=alfabeto.size();
            else if (resta>=alfabeto.size()) resta%=alfabeto.size();
            salida+=alfabeto.at(resta);
        }
        else salida+=mensaje.at(i);
    }
    return salida;
}

//void VigenereClass::setClave(string clave){this->clave=clave;}
