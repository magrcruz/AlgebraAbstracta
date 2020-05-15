#include <iostream>
#include "ViAsciiHex.h"

using namespace std;

int main()
{
    ViAsciiHex a("clave");
    string mensaje="Algebra Abstracta";
    a.cifrado(mensaje);
    a.descifrado("cifrado.txt");
    cout<<"Archivo cifrado: \"cifrado.txt\""<<endl;
    cout<<"Archivo descifrado: \"descifrado.txt\""<<endl;

    return 0;

}
