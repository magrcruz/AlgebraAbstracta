#include "RailFence.h"

RailFence::RailFence(int clave){
    this->clave=clave;
}

string RailFence::descifrado(string mensajeC){
    string salida(mensajeC);
    int k1=(clave-1)<<1, indice=0, k2=0;
    for(int i=0;i<clave;i++,k1-=2,k2+=2){
        int a=i;
        salida.at(i)=mensajeC.at(indice++);
        while(a<mensajeC.size()){//a apunta al cifrado, b al indice
            a+=k1;
            if(k1&&a<mensajeC.size())
                salida.at(a)=mensajeC.at(indice++);
            a+=k2;
            if(k2&&a<mensajeC.size())
                salida.at(a)=mensajeC.at(indice++);
        }
    }
    return salida;
}
string RailFence::cifrado(string mensajeC){
    string salida(mensajeC);
    int k1=(clave-1)<<1, indice=0, k2=0;
    for(int i=0;i<clave;i++,k1-=2,k2+=2){
        int a=i;
        salida.at(indice++)=mensajeC.at(i);
        while(a<mensajeC.size()){
            a+=k1;
            if(k1&&a<mensajeC.size())
                salida.at(indice++)=mensajeC.at(a);
            a+=k2;
            if(k2&&a<mensajeC.size())
                salida.at(indice++)=mensajeC.at(a);
        }
    }
    return salida;
}
