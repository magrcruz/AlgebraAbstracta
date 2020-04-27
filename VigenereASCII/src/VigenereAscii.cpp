#include "VigenereAscii.h"

VigenereAscii::VigenereAscii(){
    clave="Cifrado";
    alfabeto="qwertyuiopasdfghjklzxcvbnm";
    inicoAlfabeto=0;
    finAlfabeto=alfabeto.size()-1;
}


VigenereAscii::~VigenereAscii()
{
    //dtor
}
void VigenereAscii::setAlfabeto(string alf,int ini,int fin=-1){
    alfabeto=alf;
    inicoAlfabeto=ini;
    finAlfabeto=fin;
    if(fin==-1) finAlfabeto=alf.size()-1;
}

string VigenereAscii::cifrado(string mensaje){
    int actualLen=finAlfabeto-inicoAlfabeto+1;
    string salida;
    int a,b,suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.rfind(clave.at(i%clave.size()));
        b=alfabeto.rfind(mensaje.at(i));
        if (a!=string::npos&&b!=string::npos){
            suma=a+b-(inicoAlfabeto*2);
            if (suma>=alfabeto.size()) suma%=actualLen;
            suma+=inicoAlfabeto;
            salida+=alfabeto.at(suma);
        }
        else salida+=mensaje.at(i);
    }
    return salida;
}

string VigenereAscii::descifrado(string mensaje){
    string salida;
    int a,b,resta=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.rfind(mensaje.at(i));
        b=alfabeto.rfind(clave.at(i%clave.size()));
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

string VigenereAscii::cifradoModified(string mensaje){
    claveAux=clave;
    string salida;
    int a,b,suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.rfind(claveAux);
        b=alfabeto.rfind(mensaje.at(i));
        if (a!=string::npos&&b!=string::npos){
            suma=a+b;
            if (suma>=alfabeto.size()) suma%=alfabeto.size();
            salida+=alfabeto.at(suma);
            claveAux+=salida;
        }
        else salida+=mensaje.at(i);
    }
    return salida;
}

string VigenereAscii::descifradoModified(string mensaje){
    string salida;
    int a,b,resta=0;
    for (int i=0;i<mensaje.size();i++){
        a=alfabeto.rfind(mensaje.at(i));
        b=alfabeto.rfind(claveAux);
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


void VigenereAscii::setClave(string clave){this->clave=clave;}
