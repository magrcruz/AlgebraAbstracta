#include "Kasisiki.h"

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
    for(int i=0;i<subcadenas.size();i++)
        clave+=analisisFrecuenciasClave(subcadenas[i]);
    ///Continuara...

    return clave;
}

vector <int> Kasisiki::distanciaSecuenciasRepetidas(string mensaje){
    string strRepetida=mensaje.substr(0,3);
    vector <string> cadenasRepetidas;
    vector <int> distancias;
    for (int i=0;i<mensaje.size()-3;i++){
        size_t finder=mensaje.find(strRepetida,i+1);
        if (finder!=string::npos){
            cout<<"i"<<i<<endl;
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
    return mcd;
}

//ir buscando bucle cadenas de 3 char
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
        //cout<<"Frecuencia en mensaje: "<<alfabeto[i]<<" "<<frecuent[i]<<endl;//FUNCIONA
    }
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
    //string letrasFrecuentes="AEO";
    int posFrecuent[]={0,4,10+4};
    vector <int> arr(alfabeto.size());
    vector <int> sumas(alfabeto.size());
    arr=frecuencias(mensaje);
    for (int i=0;i<alfabeto.size();i++){
        sumas[i]=arr[(i+0)%alfabeto.size()];
        sumas[i]+=arr[(i+4)%alfabeto.size()];
        sumas[i]+=arr[(i+14)%alfabeto.size()];
    }
    int mayPos=findPosMayor(sumas);
    //cout<<"Mayor posicion: "<<findPosMayor(sumas)<<endl;
    return alfabeto.substr(mayPos,1);
}

int Kasisiki::findPosMayor(vector <int> arr){
    int posMayor=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[posMayor]) posMayor=i;
        //else if(arr[i]==arr[posMayor])
    }

    cout<<"posMayor: "<<arr[posMayor]<<endl;
    return posMayor;
}

