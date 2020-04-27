#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

bool even(ZZ a);
ZZ mod(ZZ a,ZZ b);
ZZ algoritmo1(ZZ a,ZZ b);
ZZ algoritmo2(ZZ a,ZZ b);
ZZ algoritmo3(ZZ a,ZZ b);
ZZ algoritmo4(ZZ a,ZZ b);
ZZ algoritmo5(ZZ a,ZZ b);
ZZ algoritmo6(ZZ a,ZZ b);
ZZ euclidesRecursivo(ZZ a,ZZ b);

int main()
{
    ZZ a,b;
    cin>>a>>b;
    cout<<"Algoritmo1: "<<endl;
    cout<<algoritmo1(a,b)<< endl;
    cout<<"Algoritmo2: "<<endl;
    cout<<algoritmo2(a,b)<< endl;
    cout<<"Algoritmo3: "<<endl;
    cout<<algoritmo3(a,b)<< endl;
    cout<<"Algoritmo4: "<<endl;
    cout<<algoritmo4(a,b)<< endl;
    cout<<"Algoritmo5: "<<endl;
    cout<<algoritmo5(a,b)<< endl;
    cout<<"Algoritmo6: "<<endl;
    cout<<algoritmo6(a,b)<< endl;
    cout<<"Euclides Recursivo: "<<endl;
    cout<<euclidesRecursivo(a,b)<< endl;

    return 0;
}

bool even(ZZ a){
    if(mod(a,ZZ(2))==0) return 1;
    return 0;
}
ZZ mod(ZZ a,ZZ b){return a-((a/b)*b);}

ZZ valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
    }
ZZ algoritmo1(ZZ a,ZZ b){
    ZZ r=mod(a,b);//p2
   while(r!=0){
        cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
        a=b;
        b=r;
        r=mod(a,b);//p2
    }
    return b;
};
ZZ algoritmo2(ZZ a,ZZ b){
    ZZ r=mod(a,b);//p2
    while(r!=0){
        cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
        if(r>b/2){
            r=b-r;
            cout<<"r: "<<r<<endl;
        }
        a=b;
        b=r;
        r=mod(a,b);//p2
    }
    return b;
}
ZZ algoritmo3(ZZ a,ZZ b){
    cout<<"a: "<<a<<" b: "<<b<<endl;
    if(b==0) return a;
    return algoritmo3(b,mod(a,b));
}
ZZ algoritmo4(ZZ a,ZZ b){
    cout<<"a: "<<a<<" b: "<<b<<endl;
    if(valAbs(b)>valAbs(a)) return algoritmo4(b,a);
    else if(b==0) return a;
    else if(even(a)&&even(b)) return 2* algoritmo4(a/2,b/2);
    else if(even(a)&&!even(b)) return algoritmo4(a/2,b);
    else if(!even(a)&&even(b)) return algoritmo4(a,b/2);
    else return algoritmo4((valAbs(a)-valAbs(b))/2,b);
}
ZZ algoritmo5(ZZ x,ZZ y){
    ZZ g=ZZ(1);
    while(even(x)&&even(y)){
        x=x/2;
        y=y/2;
        g=2*g;
        cout<<"x: "<<x<<" y: "<<y<<" g: "<<g<<endl;
    }
    while(x!=0){
        while(even(x)){
            x/=2;
            cout<<"x: "<<x<<endl;
        }
        while(even(y)){
            y/=2;
            cout<<"y: "<<y<<endl;
        }
        ZZ t=valAbs((x-y))/2;
        cout<<"t: "<<t<<endl;
        if(x>=y) x=t;
        else y=t;
        cout<<"x: "<<x<<" y: "<<y<<endl;
    }
    return (g*y);
};
ZZ algoritmo6(ZZ a,ZZ b){
    while(a!=b){
        cout<<"a: "<<a<<" b: "<<b<<endl;
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
ZZ euclidesRecursivo(ZZ a,ZZ b){
    ZZ r=mod(a,b);//p2
    cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
    if(r==0) return b;
    return euclidesRecursivo(b,r);
};
