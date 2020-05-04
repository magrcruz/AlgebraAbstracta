#include "polybiosCipher.h"

polybiosCipher::polybiosCipher(){
}

string polybiosCipher::cifrado(string mensaje){
    string cifrado;
    for (int i=0;i<mensaje.size();i++){///por cada letra del mensaje
        int aux=alfabeto.find(mensaje[i]);///busca en la matriz la posicion de la letra
        if(aux>8) aux--;///Resta 1 ya que I/J comparten posicion
        cifrado+=alfabeto.at(aux/5);///busca la columna y concatena
        cifrado+=alfabeto.at(aux%5);///busca la fila y concatena
    }
    return cifrado;
}

string polybiosCipher::descifrado(string mensajeCifrado){
    string mensaje;
    for(int i=0;i<mensajeCifrado.size();i+=2){
        ///El primer caracter corresponde a la columna y el segundo a la fila
        int aux=alfabeto.find(mensajeCifrado[i])*5+alfabeto.find(mensajeCifrado[i+1]);
        if(aux>8) aux++;///evalua si es mayor a 8 por la posicion I/J
        mensaje+=alfabeto.at(aux);///concatena en el mensaje de salida
    }
    return mensaje;
}
