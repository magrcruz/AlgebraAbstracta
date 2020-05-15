#include "ViAsciiHex.h"

ViAsciiHex::ViAsciiHex(string clave,bool Ascii){
    this->clave=clave;
}


void ViAsciiHex::cifrado(string mensaje){
    ofstream codigosCifrado("cifrado.txt");
    string salida;
    size_t a,b,suma=0;
    for (int i=0;i<mensaje.size();i++){
        a=find(alfabeto,clave.substr(i%clave.size(),1));
        b=find(alfabeto,mensaje.substr(i,1));
        if (a!=string::npos&&b!=string::npos){
            suma=a+b-2*inicioAlfabeto;
            if (suma>=(alfabeto.size()-inicioAlfabeto)) suma%=(alfabeto.size()-inicioAlfabeto);
            codigosCifrado<<alfabeto.at(suma+inicioAlfabeto)<<endl;
        }
    }
}

void ViAsciiHex::descifrado(string nombreArchivo){
    ifstream entrada(nombreArchivo);
    ofstream salida("descifrado.txt");
    string aux;
    int a,b,resta=0,i=0;
    while(getline(entrada,aux)){
        a=find(alfabeto,aux);
        b=find(alfabeto,clave.substr(i%clave.size(),1));
        if(a!=string::npos&&b!=string::npos){
            resta=a-b+inicioAlfabeto;
            if (resta<inicioAlfabeto) resta+=(alfabeto.size()-inicioAlfabeto);
            else if (resta>=alfabeto.size()-inicioAlfabeto) resta%=(alfabeto.size()-inicioAlfabeto);
            salida<<alfabeto.at(resta);
        }
        i++;
    }
}




size_t ViAsciiHex::find(vector<string> vec,string buscando){
    for(size_t pos=0;pos<vec.size();pos++)
        if(vec[pos]==buscando) return pos;
    return string::npos;
}

///string noHex[16]={"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
string ViAsciiHex::intToHex(int n){
    return "falta";
}
int ViAsciiHex::hexToInt(string hex){
    return 0;
}
string ViAsciiHex::findHex(vector<string> vec,string buscando){
    return "falta";
}

