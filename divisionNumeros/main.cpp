#include <iostream>

using namespace std;

int modulo(int a,int n){//main a funcion para hallar modulo
    int q,r;
    q=a/n;
    if(q<0) q--;
    r=a-q*n;
    cout<<"q: "<<q<<" r: "<<r<< endl;
    cout<<a<<"="<<q<<"*"<<n<<"+"<<r<<endl;
    return r;
}

int main()
{
    int a,n;
    cin>>a>>n;
    //contenido del main a funcion
    cout<<"modulo: "<<modulo(a,n);
    ///Implementacion con ZZ en Practica de Laboratorio Euclides
    return 0;
}
