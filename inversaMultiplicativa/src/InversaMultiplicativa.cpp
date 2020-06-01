#include "InversaMultiplicativa.h"

ZZ mcdAlgorithms::mod(ZZ a,ZZ b){
    ZZ q=a/b;
    if(q<0) q--;
    return a-q*b;
}

InversaMultiplicativa::InversaMultiplicativa()
{
    //ctor
}

InversaMultiplicativa::~InversaMultiplicativa()
{
    //dtor
}

ZZ InversaMultiplicativa::inversa(ZZ r1, ZZ r2){
    zz s1(1), s2(0), t1(0), t2(1);
    if (mcd(r1,r2)==1)
        while (r2>0){
            ZZ q=r1/r2;
            r1=r2;
            r2=r1-q*r2;//actualiza con el residuo
            s1=s2;
            s2=s1-q*s2;
            t1=t2;
            t2=t1-q*t2;
        }
    cout<<"s1: "<<s1<<" t1 : "<<t1<<endl;
    else cout<<"no hay"<<endl;
    return 0;
}

ZZ InversaMultiplicativa::mcd(ZZ x,ZZ y){//5
    ZZ g=ZZ(1);
    while(mod(x,ZZ(2))&&mod(y,ZZ(2))){
        x=x>>1;
        y=y>>1;
        g=g<<1;
    }
    while(x!=0){
        while(mod(x,ZZ(2)))
            x=x>>1;
        while(mod(y,ZZ(2)))
            y=y>>1;
        ZZ t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return (g*y);
}
