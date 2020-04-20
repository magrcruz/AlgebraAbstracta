#include <iostream>
#include <string>
#include <fstream>
#include "VigenereClass.h"
#include "practica2.h"
#include "Kasisiki.h"

using namespace std;

string Kasisiki::alfabeto="ABCDEFGHIJKLMNOPQRSRTUVWXYZ";

int main(){
//insertar texto cifrado manualmente 3a
    string alfNumerico="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";


    bool porConsola;
    string mensaje,aux,cifrado;
    VigenereClass a;
    a.alfabeto=alfNumerico;
    ifstream archivo("texto.txt");
    if(archivo.fail())
        cout<<"Falla en cargar el archivo"<<endl;
    else{
        while(getline(archivo,aux)){
            mensaje+=aux;
            mensaje+='\n';
        }
    }
    cifrado=a.cifrado(mensaje);
    cout<<cifrado<<endl;
    cout<<a.descifrado(cifrado)<<endl;

    string aqui=practica2::insertAQUI10W4(mensaje);
    cifrado=a.cifrado(aqui);
    cout<<cifrado<<endl;
    aux=a.descifrado(cifrado);
    aux=practica2::eliminarAQUI10W4(aux);
    cout<<aux<<endl;

    string alfAscii="ÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇ !\"#$%&'()*+'-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_´abcdefghijklmnopqrstuvwxyz{|}~Ç";
    string alfHex="";

    cout<<Kasisiki::kasiskiAtack("LNUDVMUYRMUDVLLPXAFZUEFAIOVWVMUOVMUEVMUEZCUDVSYWCIVCFGUCUNYCGALLGRCYTIJTRNNPJQOPJEMZITYLIAYYKRYEFDUDCAMAVRMZEAMBLEXPJCCQIEHPJTYXVNMLAEZTIMUOFRUFC");

}
