#include "polybiosCipher.h"

polybiosCipher::polybiosCipher(){
}

string polybiosCipher::cifrado(string mensaje){
    string cifrado;
    for (int i=0;i<mensaje.size();i++){
        int aux=alfabeto.find(mensaje[i]);
        if(aux>8) aux--;
        cifrado+=alfabeto.at(aux/5);
        cifrado+=alfabeto.at(aux%5);
    }
    return cifrado;
}

string polybiosCipher::descifrado(string mensajeCifrado){
    string mensaje;
    for(int i=0;i<mensajeCifrado.size();i+=2){
        int aux=alfabeto.find(mensajeCifrado[i])*5+alfabeto.find(mensajeCifrado[i+1]);
        if(aux>8) aux++;
        mensaje+=alfabeto.at(aux);
    }
    return mensaje;
}
