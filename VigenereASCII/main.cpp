#include <iostream>

#include "VigenereAscii.h"
using namespace std;

int main()
{
    VigenereAscii a;
    string mensaje="No te rindas";//:3
    string espacios(' ',87);
    string alfabeto="ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß !\"#$%&'()*+,'./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_´abcdefghijklmnopqrstuvwxyz{|}~ ßÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜø£Ø×ƒáíóúñÑªº¿"+espacios;
    string alfabetoPrueba=" !\"#$%&'()*+,'./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_´abcdefghijklmnopqrstuvwxyz{|}~ ßÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜø£Ø×ƒáíóúñÑªº¿";
    cout<<alfabetoPrueba<<endl;
    a.setAlfabeto(alfabeto);
    cout << a.cifrado(mensaje) << endl;
    a.setAlfabeto(alfabetoPrueba);
    cout << a.cifrado(mensaje) << endl;


    return 0;
}
