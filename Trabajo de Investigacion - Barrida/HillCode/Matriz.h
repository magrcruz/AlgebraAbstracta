#pragma once
#include <vector>
#include<iostream>
using namespace std;
class Matriz
{
private:
    int filas, columnas,det=0;
   
    
    template <class T>
    int getDeterminante(vector<vector<T>>);
    void setTranspuesta();
    template <class T>
    int cofactor(vector<vector<T>>,int,int);
    
    void calcInversa();

public:
    vector<vector<int>> matriz, transpuesta,adjunta;
    Matriz();
    Matriz(vector<vector<int>>);
    bool invertible;
    int getDet();
    bool isInvertible();
    template <class T>
    void print(vector<vector<T>>);
    vector<vector<double>>inversa;

};
template <class T>
void Matriz::print(vector<vector<T>> mat)
{
    for (vector<T>a : mat) {
        for (T b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
}

