#include "InversaM.h"

ZZ InversaM::mod(ZZ a,ZZ b){
    ZZ r=a-((a/b)*b);
    if(r<0) r=b-r;
    return r;
}

bool InversaM::even(ZZ a){
    ZZ r=(a>>1)<<1;
    if(r<0) r=2-r;
    return r==a;
}

ZZ InversaM::valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
}

ZZ InversaM::inversa(ZZ r1, ZZ r2){
    ZZ s1(1), s2(0), b=r2;
    if (hayInversa(r1,r2)){
        while (r2>0){
            ZZ q=r1/r2;
            ZZ r=r1-q*r2;
            r1=r2;
            r2=r;
            ZZ s=s1-q*s2;
            s1=s2;
            s2=s;
        }
        if(s1<0) return mod(s1,b);
        return s1;
    }
    else cout<<"no hay"<<endl;
    return ZZ(0);
}

///evalua si mcd es 1
bool InversaM::hayInversa(ZZ x,ZZ y){
    if(even(x)&&even(y)) return 0;
    while(x!=0){
        while(even(x)) x=x>>1;
        while(even(y)) y=y>>1;
        ZZ t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return y==ZZ(1);
}

/**
ZZ InversaM::mcd(ZZ x,ZZ y){//5
    ZZ g=ZZ(1);
    while(even(x)&&even(y)){
        x=x>>1;
        y=y>>1;
        g=g<<1;
    }
    while(x!=0){
        while(even(x))
            x=x>>1;
        while(even(y))
            y=y>>1;
        ZZ t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return (g*y);
}
*/
