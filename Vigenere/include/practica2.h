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
        static void imprimirArchivo(string nombreArchivo);
        static void getValues(bool &porConsola,string &clave,string &aDesCifrar);
        static string insertAQUI10W4(string mensaje);
        //static string getAscii(int n);
    protected:

    private:
};

#endif // PRACTICA2_H
