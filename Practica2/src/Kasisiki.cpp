#include "Kasisiki.h"
//Cambios para imprimir el desarrollo de Kasiski
Kasisiki::Kasisiki()
{
    //ctor
}

Kasisiki::~Kasisiki()
{
    //dtor
}
string Kasisiki::kasiskiAtack(string mensaje){
    string clave;
    vector <int> distancias=distanciaSecuenciasRepetidas(mensaje);
    int lenClave=mcd(distancias);
    vector <string> subcadenas=dividirCadena(lenClave,mensaje);
    for(int i=0;i<subcadenas.size();i++) clave+=analisisFrecuenciasClave(subcadenas[i]);
    return clave;
}

vector <int> Kasisiki::distanciaSecuenciasRepetidas(string mensaje){
    string strRepetida=mensaje.substr(0,3);
    vector <string> cadenasRepetidas;
    vector <int> distancias;
    for (int i=0;i<mensaje.size()-3;i++){
        size_t finder=mensaje.find(strRepetida,i+1);
        if (finder!=string::npos){
            cadenasRepetidas.push_back(strRepetida);
            distancias.push_back(finder-i);
        }
        strRepetida=mensaje.substr(i+1,3);
    }
    for (int i=0;i<cadenasRepetidas.size();i++) cout<<"Cadena: "<<cadenasRepetidas[i]<<" "<<distancias[i]<<" pos de separacion"<<endl;
    return distancias;
}

int Kasisiki::mcd (vector<int>a){
    int residuo,mcd,tam=a.size(),i=0;
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    for(i;i<tam;i++){
        if(i==0)
            mcd=a[0];
        do{
           residuo=mcd%a[i];
           mcd=a[i];
           a[i]=residuo;
        }
        while(residuo!=0);
    }
    cout<<endl<<"Mcd: "<<mcd<<endl;
    return mcd;
}

vector <string> Kasisiki::dividirCadena(int noSubcadenas,string mensaje){
    vector <string> subcadenas(noSubcadenas);
    int tam=mensaje.size();
    for(int i=0;i<tam/noSubcadenas;i++){
        for(int j=0;j<noSubcadenas;j++){
            subcadenas[j]+=mensaje[(i*noSubcadenas+j)];
        }
    }
    int residuo=(tam%noSubcadenas);
    if(residuo){
        for (int i=0;i<residuo;i++){
            subcadenas[i]+=mensaje[tam-residuo+i];
        }
    }
    for (int i=0;i<noSubcadenas;i++) cout<<"Subcadena "<<i<<": "<<subcadenas[i]<<endl;
    return subcadenas;
}

vector<int> Kasisiki::frecuencias(string mensaje){
    vector <int> frecuent(alfabeto.size());
    for (int i=0;i<frecuent.size();i++){
        frecuent[i]=countInString(alfabeto.substr(i,1),mensaje);
    }
    cout<<endl<<"Frecuencias:"<<endl;
    for(int i=0;i<alfabeto.size();i++) cout<<setw(3)<<alfabeto.at(i);
    cout<<endl;
    for(int i=0;i<alfabeto.size();i++) cout<<setw(3)<<frecuent.at(i);
    cout<<endl;
    return frecuent;
}

int Kasisiki::countInString(string buscar, string mensaje){
    int counting=0;
    size_t finder=mensaje.find(buscar);
    while (finder!=string::npos){
        counting++;
        finder=mensaje.find(buscar,finder+1);
    }
    return counting;
}

string Kasisiki::analisisFrecuenciasClave(string mensaje){
    int posFrecuent[]={0,4,11+4};//modificacion de distancias para el idioma espaniol
    vector <int> arr(alfabeto.size());
    vector <int> sumas(alfabeto.size());
    arr=frecuencias(mensaje);
    for (int i=0;i<alfabeto.size();i++){
        sumas[i]=arr[(i+posFrecuent[0])%alfabeto.size()];
        sumas[i]+=arr[(i+posFrecuent[1])%alfabeto.size()];
        sumas[i]+=arr[(i+posFrecuent[2])%alfabeto.size()];
    }
    int mayPos=findPosMayor(sumas);
    return alfabeto.substr(mayPos,1);
}

int Kasisiki::findPosMayor(vector <int> arr){
    cout<<endl<<"Suma:"<<endl;
    for(int i=0;i<alfabeto.size();i++) cout<<setw(3)<<alfabeto.at(i);
    cout<<endl;
    for(int i=0;i<arr.size();i++) cout<<setw(3)<<arr.at(i);
    cout<<endl;
    int posMayor=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[posMayor]) posMayor=i;
    }
    return posMayor;
}

