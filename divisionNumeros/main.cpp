#include <iostream>

using namespace std;

void divison(int a,int n,int &q,int&r){


}

int main()
{
    //a = q*n + r
    int a,q,n,r;
    bool negativo=0;
    cin>>a>>n;
    q=a/n;
    if(q<0) q--;
    r=a-q*n;
    cout<<"q: "<<q<<" r: "<<r<< endl;
    cout<<a<<"="<<q<<"*"<<n<<"+"<<r<<endl;
    return 0;
}
