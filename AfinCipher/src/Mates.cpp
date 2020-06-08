#include "Mates.h"

int Mates::mod(int a,int b){
    int r=a-((a/b)*b);
    if(r<0) r=b-r;
    return r;
}

bool Mates::even(int a){
    int r=(a>>1)<<1;
    if(r<0) r=2-r;
    return r==a;
}

int Mates::valAbs(int a){
    if (a<0) return (a*-1);
    return a;
}

int Mates::inversa(int r1, int r2){
    int s1=1, s2=0, b=r2;
    if (hayInversa(r1,r2)){
        while (r2>0){
            int q=r1/r2;
            int r=r1-q*r2;
            r1=r2;
            r2=r;
            int s=s1-q*s2;
            s1=s2;
            s2=s;
        }
        if(s1<0) return mod(s1,b);
        return s1;
    }
    else cout<<"No tiene inversa"<<endl;
    return 0;
}

///evalua si mcd es 1
bool Mates::hayInversa(int x,int y){
    if(even(x)&&even(y)) return 0;
    while(x!=0){
        while(even(x)) x=x>>1;
        while(even(y)) y=y>>1;
        int t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return y==1;
}

int Mates::mcd(int x,int y){//5
    int g=int(1);
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
        int t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return (g*y);
}

int Mates::aleatorio(int limite){
    srand(time(NULL));
    return mod(rand(),limite);
}
