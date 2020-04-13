#ifndef PRACTICA1_H
#define PRACTICA1_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Practica1
{
    public:
        static string charToStr(char arr[],int tam);
        static string mayToMin(string &in);
        static int contarInStr(string frase,string palabra);
        static void printEnLineas(string cadena);
        static void buscarYremplazar(string &primero,string segundo,string tercero);
        static void writeNnumeros(int n);
        static int sumatoriaArchivo();
        static string cifrado(string str,bool cifrar=true,int root=13);
        static void juegoAhorcado();
        static void signToToken(string in);

        static void ordenar(bool a,string arr1[],int tam);
        static void ordenSeleccion(string arr[],int tam,bool (*compare)(string,string));
        static bool ascendente(string a, string b){return a.compare(b)<0;}//a<b
        static bool descendente(string a, string b){return a.compare(b)>0;}//a>b


        template <typename T>
        static void printArr(T* start,T* ends){
            while(start!=ends){
                cout<<*start<<" ";
                start++;
            }
            cout<<endl;
        }
    protected:

    private:
        virtual void claseAbstracta()=0;
        static bool isChar(char a);
        static void revelarInStr(string &base,string respuesta,string key);
        static void drawMan(int intentos);
        static string obtenerPalabra();
};

#endif // PRACTICA1_H
