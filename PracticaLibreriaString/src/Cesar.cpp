#include "Cesar.h"
Cesar::Cesar(){
    this->alfabeto="abcdefghijklmnopqrstuvwxyz";
    this->clave=13;
}

Cesar::Cesar(int clave,string alfabeto){
    this->alfabeto=alfabeto;
    this->clave=clave%26;
}

string Cesar::cifrado(string mensaje){
    string alfAux(alfabeto+alfabeto);
    for (int i=0;i<mensaje.size();i++){
        size_t pos=alfabeto.find(mensaje[i]);
        if(pos!=string::npos)
            mensaje[i]=alfAux.at(pos+clave);
    }
    cout<<"mensaje cifrado: "<<mensaje<<endl;
    return mensaje;
}


string Cesar::descifrado(string mensaje){
    string alfAux(alfabeto+alfabeto);
    for (int i=0;i<mensaje.size();i++){
        size_t pos=alfAux.rfind(mensaje[i]);
        if(pos!=string::npos)
            mensaje[i]=alfAux.at(pos-clave);
    }
    cout<<"mensaje normal: "<<mensaje;
    return mensaje;

}
