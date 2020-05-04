#include "ViAsciiHex.h"

ViAsciiHex::ViAsciiHex(string clave,bool Ascii){
    this->clave=clave;
}

ViAsciiHex::~ViAsciiHex()
{
    //dtor
}
string ViAsciiHex::cifrado(string mensaje){
    ofstream codigosCifrado("cifradoNo.txt");
    string salida;
    size_t a,b,suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=find(alfabeto,clave.substr(i%clave.size(),1));
        b=find(alfabeto,mensaje.substr(i,1));
        if (a!=string::npos&&b!=string::npos){
            suma=a+b-2*inicioAlfabeto;
            if (suma>=(alfabeto.size()-inicioAlfabeto)) suma%=(alfabeto.size()-inicioAlfabeto);
            salida+=alfabeto.at(suma+inicioAlfabeto);
            codigosCifrado<<(suma+inicioAlfabeto)<<endl;
        }
        else salida+=mensaje.at(i);
    }

    crearArchivo(salida);
    return salida;
}
string ViAsciiHex::descifradoSumas(string nombreArchivo){
    int a=0,b,resta;
    string salida;
    ifstream archivo(nombreArchivo);
    string lineArchivo;
    while(getline(archivo,lineArchivo)){
        int i=0;
        b=find(alfabeto,clave.substr(i%clave.size(),1));
        a=stoi(lineArchivo);
        resta=a-b-2*inicioAlfabeto;
        if (resta<0) resta+=(alfabeto.size()-inicioAlfabeto);
        else if (resta>=alfabeto.size()-inicioAlfabeto) resta%=(alfabeto.size()-inicioAlfabeto);
        salida+=alfabeto.at(resta+inicioAlfabeto);
        i++;
    }
    archivo.close();
    return salida;
}


string ViAsciiHex::descifrado(string mensaje){
    string salida;
    int a,b,resta=0;
    for (int i=0;i<mensaje.size();i++){
        a=find(alfabeto,mensaje.substr(i,1));
        b=find(alfabeto,clave.substr(i%clave.size(),1));
        if(a!=string::npos&&b!=string::npos){
            resta=a-b-2*inicioAlfabeto;
            if (resta<0) resta+=(alfabeto.size()-inicioAlfabeto);
            else if (resta>=alfabeto.size()) resta%=(alfabeto.size()-inicioAlfabeto);
            salida+=alfabeto.at(resta+inicioAlfabeto);
        }
        else salida+=mensaje.at(i);
    }
    return salida;
}

string ViAsciiHex::leerTxt(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    string actual;
    string salida;
    while(getline(archivo,actual)){
        salida+=actual;
    }
    archivo.close();
    return salida;
}
void ViAsciiHex::crearArchivo(string mensaje){
    ofstream archivo("cifrado.txt");
    archivo<<mensaje;
    archivo.close();
}

/*
vector<string> ViAsciiHex::strToVecStr(string str){
    ///example find wDELwholis
    vector<string> salida;
    for (int i=0;i<str.size();i++){
        if(str.at(i)==w){///posible char de control
                //>5 <3

            size_t endCtrlStr=str.find('w',i+1);
            size_t lenCharCtrl=i-endCtrlStr;
            if(lenCharCtrl>=3;lenCharCtrl<=5)///es char de control
                salida
            i+=lenCharCtrl-1;
        }

    }

}
*/

size_t ViAsciiHex::find(vector<string> vec,string buscando){
    for(size_t pos=0;pos<vec.size();pos++)
        if(vec[pos]==buscando) return pos;
    return string::npos;
}
