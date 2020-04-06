#ifndef PRACTICA1_H
#define PRACTICA1_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Practica1
{
    public:
        Practica1();
        virtual ~Practica1();
        static string charToStr(char arr[],int tam);
        static void printArr(char* start,char*ends);
        static string mayToMin(string &in);
        static int contarInStr(string frase,string palabra);
        static void printEnLineas(string cadena);
        static void buscarYremplazar(string &primero,string segundo,string tercero);
        static void writeNnumeros(int n);
        static int sumatoriaArchivo();
        static string cifrado(string str,bool cifrar=true,int root=13);
        static void juegoAhorcado();

    protected:

    private:
        virtual void claseAbstracta()=0;
        static bool isChar(char a);
        static void revelarInStr(string &base,string respuesta,string key);
        static void drawMan(int intentos);
        static string obtenerPalabra();
};

#endif // PRACTICA1_H
