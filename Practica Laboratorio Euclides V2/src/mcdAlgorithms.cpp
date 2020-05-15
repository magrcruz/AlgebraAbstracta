#include "mcdAlgorithms.h"

ZZ mcdAlgorithms::mods(ZZ a,ZZ b){
    ZZ q=a/b;
    if(q<0) q--;
    return a-q*b;
}

bool mcdAlgorithms::even(ZZ a){
    if(mods(a,ZZ(2))==0) return 1;
    return 0;
}

ZZ mcdAlgorithms::valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
    }
ZZ mcdAlgorithms::algoritmo1(ZZ a,ZZ b){
    ZZ r=mods(a,b);//p2
    while(r!=0){
        cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
        a=b;
        b=r;
        r=mods(a,b);//p2
    }
    return b;
}
ZZ mcdAlgorithms::algoritmo2(ZZ a,ZZ b){
    ZZ r=mods(a,b);//p2
    while(r!=0){
        cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
        if(r>b/2){
            r=b-r;
            cout<<"r: "<<r<<endl;
        }
        a=b;
        b=r;
        r=mods(a,b);//p2
    }
    return b;
}
ZZ mcdAlgorithms::algoritmo3(ZZ a,ZZ b){
    cout<<"a: "<<a<<" b: "<<b<<endl;
    if(b==0) return a;
    return algoritmo3(b,mods(a,b));
}
///Dos versiones de Alg. 4 sin corrimiento y con corrimiento (algoritmo4bitwise)
ZZ mcdAlgorithms::algoritmo4(ZZ a,ZZ b){
    cout<<"a: "<<a<<" b: "<<b<<endl;
    if(valAbs(b)>valAbs(a)) return algoritmo4(b,a);
    else if(b==0) return a;
    else if(even(a)&&even(b)) return 2* algoritmo4(a/2,b/2);
    else if(even(a)&&!even(b)) return algoritmo4(a/2,b);
    else if(!even(a)&&even(b)) return algoritmo4(a,b/2);
    else return algoritmo4((valAbs(a)-valAbs(b))/2,b);
}
ZZ mcdAlgorithms::algoritmo4bitwise(ZZ a,ZZ b){
    if(valAbs(b)>valAbs(a)) return algoritmo4(b,a);
    else if(b==0) return a;
    else if(even(a)&&even(b)) return algoritmo4(a>>1,b>>1)<<1;
    else if(even(a)&&!even(b)) return algoritmo4(a>>1,b);
    else if(!even(a)&&even(b)) return algoritmo4(a,b>>1);
    else return algoritmo4((valAbs(a)-valAbs(b))>>1,b);
}
///Dos versiones de Alg. 5 sin corrimiento y con corrimiento (algoritmo5bitwise)
ZZ mcdAlgorithms::algoritmo5(ZZ x,ZZ y){
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
}
ZZ mcdAlgorithms::algoritmo5bitwise(ZZ x,ZZ y){
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



ZZ mcdAlgorithms::algoritmo6(ZZ a,ZZ b){
    while(a!=b){
        cout<<"a: "<<a<<" b: "<<b<<endl;
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
ZZ mcdAlgorithms::euclidesRecursivo(ZZ a,ZZ b){
    ZZ r=mods(a,b);//p2
    cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<endl;
    if(r==0) return b;
    return euclidesRecursivo(b,r);
}
ZZ mcdAlgorithms::euclidesIterativo(ZZ a,ZZ b){
    ZZ r=mods(a,b);//p2
    while(b>0){
        ZZ q=a/b;
        ZZ r=a-q*b;
        a=b;
        b=r;
        cout<<"a: "<<a<<" b: "<<b<<" r: "<<r<<" q: "<<q<<endl;
    }
    return a;
}

