#include "funciones.h"

ZZ mod(ZZ a,ZZ n){
    ZZ q=a/n;
    if(q<0) q--;
    return a-(n*q);
}

bool even(ZZ a){
    ZZ r=(a>>1)<<1;
    if(r<0) r=ZZ(2)+r;
    return r==a;
}

ZZ valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
}

ZZ inversa(ZZ r1, ZZ r2){
    ZZ s1=ZZ(1), s2=ZZ(0), b=ZZ(r2);
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
        if(s1<0) return s1+=b;
        return s1;
    }
    else cout<<"No tiene inversa"<<endl;
    return ZZ(0);
}

///evalua si mcd es 1
bool hayInversa(ZZ x,ZZ y){
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

ZZ mcd(ZZ x,ZZ y){//5
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
//version antigua de aleatorio no usada
ZZ aleatorio(ZZ limite){
    srand (time(NULL));
    return mod(ZZ(rand()),limite-1)+1;
}

ZZ expModular(ZZ base, ZZ exp,const ZZ n){
    ZZ salida(1);
    do{
        if(!even(exp))
            salida=mod(salida*base, n);
        base=mod(base*base,n);
        exp>>=1;
    }while(exp!=ZZ(0));
    return salida;
}

int modint(int a,int n){
    int q=a/n;
    if(q<0) q--;
    return a-(n*q);
}
//version antigua de aleatorio no usada
int aleatorioint(int limite){
    srand (time(NULL));
    return modint(rand(),limite-1)+1;
}
