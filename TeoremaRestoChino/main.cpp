#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <fstream>
using namespace std;
using namespace NTL;

ZZ valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
}
bool even(ZZ a){
    ZZ r=(a>>1)<<1;
    if(r<0) r=ZZ(2)+r;
    return r==a;
}
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

ZZ mod(ZZ a,ZZ n){
    ZZ q=a/n;
    if(q<0) q--;
    return a-q*n;
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
        if(s1<0) return mod(s1,b);
        return s1;
    }
    else cout<<"No tiene inversa"<<endl;
    return ZZ(0);
}

ZZ mcd(ZZ x,ZZ y){//5
    ZZ g(1);
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

vector<ZZ> inputValues(){
    ///ecuacion de la forma ki x = ai mod pi, se ingresa de la forma "ki,ai,pi," cada ecuacion
    ifstream archivo("sistemaEcuaciones.csv");
    vector <ZZ> values;
    string line;
    while(getline(archivo,line)){
        for(size_t i=0,j=line.find(",",i+1);j!=string::npos;i=j,j=line.find(",",++i)){
            values.push_back(conv<ZZ>(line.substr(i,j-i).c_str()));
        }
    }
    archivo.close();
    return values;
}

void TeoremaRestoChino(){
    vector<ZZ> values(inputValues());
    for(int i=0;i<values.size();i+=3){
        if(values.at(i)!=1)
            values.at(i+1)=mod(inversa(values.at(i),values.at(i+2))*values.at(i+1),values.at(i+2));
    }
    for(int i=0;i<values.size()-1;i+=3)
        for(int j=i+3;j<values.size();j+=3)
            if(mcd(values.at(i),values.at(j))!=ZZ(1)){
                cout<<"No tiene solucion porque no son coprimos entre si"<<endl;
                return;
            }
    ZZ P=values.at(2);//p1
    for(int i=5;i<values.size();i+=3)
        P*=values.at(i);
    ZZ x0;
    for(int i=2;i<values.size();i+=3){
        ZZ pi=values.at(i);
        ZZ Pi=(P/pi);
        ZZ qi=(mod(inversa(mod(Pi,pi),pi),pi));
        x0+=mod(values.at(i-1)*Pi*qi,P);
    }
    x0=mod(x0,P);
    cout<<"X= "<<x0<<" + "<<P<<"k"<<endl;
}

int main()
{
    TeoremaRestoChino();
    return 0;
}
