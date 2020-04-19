#ifndef PRACTICA2_H
#define PRACTICA2_H
#include <iostream>
#include <string>
#include <fstream>
#include "VigenereClass.h"
using namespace std;

class practica2
{
    public:
        practica2();
        virtual ~practica2();
        static void imprimirArchivo(string nombreArchivo);
        static void ParaCifrarVigenere();
        static void paraDescifrarVigenere();
        static string insertAQUI10yCifrar(string mensaje);
        //static string getAscii(int n);
    protected:

    private:
};

#endif // PRACTICA2_H
