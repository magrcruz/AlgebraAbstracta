#include <iostream>
#include "Rsa.h"
using namespace std;

int main()
{
    string mensaje;
    Rsa receptor(512);//genera claves y recibe mensaje
    /*
    ZZ n= conv<ZZ>("103749802577063918400295917165950717770832750229590631325847870755148609170124650789919977489366550857906332321239877881565234103515777770091542034626156792878491217027966695382012662523269882457152822275606545821884350522556882707294285944497822678940495405852935033870288692765274501126626073229150739484801");
    ZZ e= conv<ZZ>("32089");//*/
    /*
    ZZ n,e;
    cin>>n>>e;//*/
    /*
    Rsa emisor(n,e);//recibe claves <n,e> y encripta mensaje
    cout<<"mensaje cifrado: "<<endl<<emisor.cifrado(mensaje)<<endl;//*/
    cin>>mensaje;
    cout<<receptor.descifrado(mensaje);//*/
    return 0;
}

