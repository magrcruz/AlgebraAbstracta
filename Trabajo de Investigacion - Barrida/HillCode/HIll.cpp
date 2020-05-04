// HIll.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include "Matriz.h"
#include "HillCode.h"
#include "OperMatrices.h"

using namespace std;
int main()
{
    /*15 3 42
    55 16 23
    23 37 36*/

    /*20 13 43
    35 48 44
    23 43 46
    */

    vector<int> a, b, c, d, e, f, g, h, i;
    a = { 6,24,1 };
    b = { 13,16,10 };
    c = { 20,17,15 };

    e = { 3,3 };
    f = { 2,5 };

    g = { 2,11,0 };
    h = {22,4,4};
    i = {9,4,12};
    vector<vector<int>>  mat1, mat2, mat3;

    std::cout << "Hello World!\n";
    mat1 = { a,b,c };
    mat2 = { e,f };
    mat3 = {g,h,i};
    Matriz clave(mat1);
    /*Matriz clave2(mat2);
    Matriz clave3(mat3);*/
    OperMatrices oper;
    HillCode hc(clave);

    cout << "ingrese mensaje" << endl;
    string mensaje;
    getline(cin, mensaje);
    string cif = hc.cirfado(mensaje);

    cout << "cifrado: "<< cif<< endl;
    cout << "descifrado: " << hc.descifrado(cif) << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln


