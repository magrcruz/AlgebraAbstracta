#include "MonomioBinomio.h"

MonomioBinomio::MonomioBinomio(string claves,string keyword){
    this->claves=claves;
    this->keyword=keyword;
    alfabeto="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

    ///ARMAR TABLERO
    tablero=alfabeto;
    for(int i=0;i<keyword.size();i++)
        tablero.erase(tablero.find(keyword.at(i)),1);
    tablero=keyword+tablero;
    for(int i=0;i<claves.size();i++)
        tablero.insert(stoi(claves.substr(i,1))," ");
    int falta=mod_positive(tablero.size(),10);
    if(falta)
        for(int i=falta;i<=10;i++) tablero+="#";
}

int MonomioBinomio::mod_positive(int a,int n){//main a funcion para hallar modulo
    int q=a/n;
    return a-(q*n);
}

string MonomioBinomio::cifrado(string mensaje){
    string salida;
    for(int i=0;i<mensaje.size();i++){
        int pos=tablero.find(mensaje.substr(i,1));
        if(pos<10) salida+=to_string(pos);
        else{
            int q=pos/10;
            salida+=claves.at(q-1);
            salida+=to_string(pos-q*10);
        }
    }
    return salida;
}

string MonomioBinomio::descifrado(string mensaje){
    string salida;
    for(int i=0;i<mensaje.size();i++){
        size_t onBoard=claves.find(mensaje.substr(i,1));//busca si esta en claves
        if(onBoard==string::npos)//no esta en las claves entonces es monomio
            salida+=tablero.at(stoi(mensaje.substr(i,1)));
        else{//si esta en claves
            i++;
            int letra=(onBoard+1)*10+stoi(mensaje.substr(i,1));//puede ser 2 o 10, ignora la primera fila
            salida+=tablero.at(letra);
        }
    }
    return salida;
}
