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
    do{
        a= Mates::aleatorio(500);
    }while(!Mates::hayInversa(a,alfabeto.size()));
    b= Mates::aleatorio(alfabeto.size());
}


/**
Afin ()
{ alf = {ab...z}
Generar claves(int a, int b) // emisor
}
Afin (int a, int b)
{
 Inva = inversa(a,tamAlf)
b=b;
}

Generar claves( )
{a= aleatorio(); // srand
aa = 1mcd_euclides(a,tamAlf)
while (aa!=1) {
Aleatorio
aa = 1mcd_euclides(a,tamAlf)}
a=aa;

b=aleatorio();
}

Main ()
{
   Afin a(); //emisor
Afin b(a,b)

a.cifrado(mensaje)
b. Descifrado (men-cifrado)
}

*/
