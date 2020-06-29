#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <fstream>
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\Funciones.h"
using namespace std;
using namespace NTL;

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

ZZ TeoremaRestoChino(){///ecuaciones de la forma ki x = ai mod pi, vector compuesto por "ki,ai,pi," por ecuacion
    vector<ZZ> values(inputValues());
    for(int i=0;i<values.size();i+=3){
        if(values.at(i)!=1)
            values.at(i+1)=mod(inversa(values.at(i),values.at(i+2))*values.at(i+1),values.at(i+2));
    }///en el caso x este multiplicada por una constante trabaja con la inversa en la congruencia
    for(int i=0;i<values.size()-1;i+=3)
        for(int j=i+3;j<values.size();j+=3)
            if(mcd(values.at(i),values.at(j))!=ZZ(1)){
                cout<<"No tiene solucion porque no son coprimos entre si"<<endl;
                return ZZ(0);
            }
    ZZ P=values.at(2);//p1
    for(int i=5;i<values.size();i+=3) P*=values.at(i);//Encuentra el valor de P
    ZZ x0;
    for(int i=2;i<values.size();i+=3){
        ZZ pi=values.at(i);
        ZZ Pi=(P/pi);
        ZZ qi=(mod(inversa(mod(Pi,pi),pi),pi));
        x0+=mod(values.at(i-1)*Pi*qi,P);
    }
    return mod(x0,P);
}

int main()
{
    cout<<TeoremaRestoChino();
    ///Obtiene las ecuaciones (ki x = ai mod pi) de la forma "ki,ai,pi," del archivo "sistemaEcuaciones.csv"
    return 0;
}
