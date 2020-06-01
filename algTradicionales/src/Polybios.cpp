#include "Polybios.h"

Polybios::Polybios(){
    alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

string Polybios::cifrado(string mensaje){
    string salida;
    for (int i=0;i<mensaje.size();i++){
        int aux=alfabeto.find(mensaje.at(i));
        if(aux>8) aux--;//Resta 1 ya que I/J comparten posicion
        int q=aux/5;//ambas operaciones hacen la division, para no hacerlo 2 veces
        salida+=alfabeto.at(q);
        salida+=alfabeto.at(aux-q*5);//busca la columna y fila
    }
    return salida;
}

string Polybios::descifrado(string mensaje){
    string salida;
    for(int i=0;i<mensaje.size();i+=2){
        int aux=alfabeto.find(mensaje.at(i))*5+alfabeto.find(mensaje.at(i+1));
        if(aux>8) aux++;//evalua si es mayor a 8 por la posicion I/J
        salida+=alfabeto.at(aux);
    }
    return salida;
}
