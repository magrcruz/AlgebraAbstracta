#include <iostream>
#include "ViAsciiHex.h"

using namespace std;

int main()
{
    ViAsciiHex a("clave");
    string mensaje="Imooto";
    a.cifrado(mensaje);
    cout<<a.descifradoSumas("descifrado.txt")<<endl;
    cout << hex << 15 << endl;
    return 0;
}
