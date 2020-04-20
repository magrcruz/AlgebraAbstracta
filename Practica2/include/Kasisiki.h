#ifndef KASISIKI_H
#define KASISIKI_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
