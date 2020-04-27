#include <iostream>
#include <string>
#include <fstream>
#include "VigenereClass.h"
#include "practica2.h"
#include "Kasisiki.h"

using namespace std;

string Kasisiki::alfabeto="ABCDEFGHIJKLMÑNOPQRSTUVWXYZ";//Correccion de alfabeto espaniol Kasiski

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

    //Aniadido demostracion Kasiski
    mensaje="LNUDVMUYRMUDVLLPXAFZUEFAIOVWVMUOVMUEVMUEZCUDVSYWCIVCFGUCUNYCGALLGRCYTIJTRNNPJQOPJEMZITYLIAYYKRYEFDUDCAMAVRMZEAMBLEXPJCCQIEHPJTYXVNMLAEZTIMUOFRUFC";
    cout<<"Mensaje: "<<endl<<mensaje<<endl;
    cout<<Kasisiki::kasiskiAtack(mensaje);
    VigenereClass c("RAUL");
    c.alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<endl<<endl<<"Mensaje Descifrado: "<<endl;
    cout<<c.descifrado(mensaje)<<endl<<endl;

    //practica en clase cifrado y descifrado
    VigenereClass b;
    b.alfabeto="abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
    b.setClave("Maria Graciel Cruz Caceres 191-10-44795");
    mensaje=b.cifrado("The MEgraph application used to display this network combines techniques such as topological range searching and motion highlighting to enable interactive exploration of complex network diagrams");
    cout<<"Mensaje cifrado:"<<endl<<mensaje<<endl;
    string aDescifrar="soTqrKC4JCglwsYTsz EvLAVwOCEDrp5-jeMcf8tqRtAGeCYWDNeAdqRIEz umzE6eI2QU5yiD3eQ765t85eTusKC,wHtBBoLDJFoJwBYTpEgAQrm6ZV,Zok6km7aLGxyCaQCnEhERIrvtvhXQ3gEeBYicc-k8Nhk9bj. BvCrYHjp-yrrC,yztLsOIfhEeyP1k";
    b.setClave("Javier Oswaldo Alvarez Reyes 181-10-42234");
    cout<<"Mensaje 2 descifrado:"<<endl<<b.descifrado(aDescifrar)<<endl;
    aDescifrar="shzGQVE3sJhJdBNLtxaImLLfyOivYkmrC9iOf2qtnQiLGrvR8ELkJfAKBtGeHCQCTlJmGS5qrRl2Gu2ktnXpHtsxGQsF Ad-EEJLerv-FZrCCsL4ydNk8Nhs9baQlBolIG.yUtzBsLAmEePmKRVvygJGmcrDofKij2mcXnTwjPA0CJlp MLECPoGoXBZeCvsKj";
    cout<<"Mensaje 1 descifrado:"<<endl<<b.descifrado(aDescifrar)<<endl;


}
