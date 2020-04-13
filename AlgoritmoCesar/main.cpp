#include <iostream>
#include <string>
#include "Cesar.h"

using namespace std;

int main()
{
    Cesar emisor,receptor;
    string mensaje;
    //cin>>mensaje;
    getline(cin,mensaje);
    string mensajeCifrado= emisor.cifrado(mensaje);
    receptor.descifrado(mensajeCifrado);
    return 0;
}
