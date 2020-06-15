#include <iostream>
#include "Rsa.h"
using namespace std;

int main()
{
    Rsa receptor;//genera claves y recibe mensaje

    Rsa emisor(receptor.n,receptor.e);//recibe claves y encripta mensaje
    emisor.cifrado("MENSAJE");//cifra mensaje de la string o cifra de message.txt
    //Guarda mensaje en cipherMessage.txt

    receptor.descifrado();//descifra cipherMessage.txt y guarda en decipher
    receptor.numbersLetters();


    return 0;
}
