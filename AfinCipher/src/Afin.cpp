#include "Afin.h"
Afin::Afin(){
    generarClaves();
    cout<<"a: "<<a<<" b: "<<b<<endl;
}
Afin::Afin (int a, int b){
    invA= Mates::inversa(a,alfabeto.size());
    this->b=b;
}

string Afin::cifrado(string mensaje){
    string salida;
    for(int i=0;i<mensaje.size();i++){
        size_t m= alfabeto.find(mensaje.at(i));
        salida += alfabeto.at(Mates::mod(a*m +b,alfabeto.size()));
    }
    return salida;
}
string Afin::descifrado(string mensaje){
    string salida;
    for(int i=0;i<mensaje.size();i++){
        size_t y= alfabeto.find(mensaje.at(i));
        salida += alfabeto.at(Mates::mod(invA*(y-b),alfabeto.size()));
    }
    return salida;
}

void Afin::generarClaves(){
    b= Mates::aleatorio(alfabeto.size());
    do{
        a= Mates::aleatorio(alfabeto.size());
    }while(!Mates::hayInversa(a,alfabeto.size()));
}
