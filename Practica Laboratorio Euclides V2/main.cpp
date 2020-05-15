#include <iostream>
#include <NTL/ZZ.h>
#include "mcdAlgorithms.h"

using namespace std;
using namespace NTL;

/**
CAMBIOS:
    - Operacion modulo mejorada
    - Implementacion de dos nuevas versiones del algoritmo 4 y 5 con operaciones bitwise:
        algoritmo4bitwise(a,b) y algoritmo5bitwise(a,b)
*/

int main()
{
    ZZ a,b;
    cin>>a>>b;
    cout<<"Algoritmo1: "<<endl;
    cout<<mcdAlgorithms::algoritmo1(a,b)<< endl;
    cout<<"Algoritmo2: "<<endl;
    cout<<mcdAlgorithms::algoritmo2(a,b)<< endl;
    cout<<"Algoritmo3: "<<endl;
    cout<<mcdAlgorithms::algoritmo3(a,b)<< endl;
    cout<<"Algoritmo4: "<<endl;
    cout<<mcdAlgorithms::algoritmo4(a,b)<< endl;
    cout<<"Algoritmo5: "<<endl;
    cout<<mcdAlgorithms::algoritmo5(a,b)<< endl;
    cout<<"AlgoritmoBitwise4: "<<endl;
    cout<<mcdAlgorithms::algoritmo4bitwise(a,b)<< endl;
    cout<<"AlgoritmoBitwise5: "<<endl;
    cout<<mcdAlgorithms::algoritmo5bitwise(a,b)<< endl;
    cout<<"Algoritmo6: "<<endl;
    cout<<mcdAlgorithms::algoritmo6(a,b)<< endl;
    cout<<"Euclides Recursivo: "<<endl;
    cout<<mcdAlgorithms::euclidesRecursivo(a,b)<< endl;
    cout<<"Euclides Iterativo(diapositiva): "<<endl;
    cout<<mcdAlgorithms::euclidesIterativo(a,b)<< endl;
    return 0;
}
