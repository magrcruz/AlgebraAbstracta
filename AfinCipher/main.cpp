#include <iostream>
#include "Afin.h"
using namespace std;

int main()
{
    Afin emisor;
    Afin receptor(27,1);
    cout<<receptor.descifrado("IPMB")<<endl;
    return 0;
}
