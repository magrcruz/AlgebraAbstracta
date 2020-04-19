#include <iostream>
#include <string>

#include "polybiosCipher.h"

using namespace std;

string polybiosCipher::alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    //No funciona con espacios
    string mensaje;
    getline(cin,mensaje);
    mensaje=polybiosCipher::cifrado(mensaje);
    cout<<"cifrado: "<<mensaje<<endl;
    cout<<"descifrado: "<<polybiosCipher::descifrado(mensaje)<<endl;
    return 0;
}
