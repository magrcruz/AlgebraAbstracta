#include <iostream>
#include "Rsa.h"
using namespace std;

int main()
{
    Rsa receptor;
    Rsa emisor(receptor.n, receptor.e);
    emisor.cifrado("TI");
    receptor.descifrado();
    receptor.numbersLetters();
    return 0;
}
