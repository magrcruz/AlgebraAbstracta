#ifndef KASISIKI_H
#define KASISIKI_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//Eliminacion de libreria no usada Algorithm y aniadir imanip para imprimir el proceso de Kasiski detallado

using namespace std;

class Kasisiki
{
    public:
        Kasisiki();
        virtual ~Kasisiki();
        static string kasiskiAtack(string mensaje);
        static vector<int> distanciaSecuenciasRepetidas(string mensaje);
        static int mcd (vector<int>a);
        static vector <string> dividirCadena(int noSubcadenas,string mensaje);
        static vector <int> frecuencias(string mensaje);

        static string analisisFrecuenciasClave(string mensaje);
        static int countInString(string buscar, string mensaje);
        static string alfabeto;
    protected:

    private:
        static int findPosMayor(vector <int> arr);
};

#endif // KASISIKI_H
