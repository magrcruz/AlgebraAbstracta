#include <iostream>
#include "Polybios.h"
#include "RailFence.h"
#include "MonomioBinomio.h"
using namespace std;

int main()
{

    RailFence rail(4);
    cout<<rail.cifrado("ESTEESUNMENSAJECIFRADO")<<endl;
    cout<<rail.descifrado("EUARSSNSJFATEMNEIDEECO")<<endl;

    MonomioBinomio mobi;
    cout<<mobi.cifrado("ESTEESUNMENSAJECIFRADO")<<endl;
    cout<<mobi.descifrado("1972119733281394251216225408")<<endl;

    Polybios poly;
    cout<<poly.cifrado("ESTEESUNMENSAJECIFRADO")<<endl;
    cout<<poly.descifrado("AEDCDDAEAEDCDECCCBAECCDCAABDAEACBDBADBAAADCD")<<endl;

    return 0;

}
