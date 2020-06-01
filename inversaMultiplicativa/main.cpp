#include <iostream>
#include <chrono>
#include "InversaM.h"

using namespace std;

int main()
{
    ZZ a,b;
    cin>>a>>b;
    InversaM inv;
    cout<<inv.inversa(a,b)<<endl;
    return 0;
}

