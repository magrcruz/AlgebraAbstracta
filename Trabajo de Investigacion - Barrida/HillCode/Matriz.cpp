#include "Matriz.h"
#include <iostream>
bool Matriz::isInvertible()
{
	if(filas != columnas)
		return false ;
	if( det == 0)
		return false;
	return true;
}

template <class T>
int Matriz::cofactor(vector<vector<T>> aux,int row,int col)
{
	int val;
	if (aux[0].size() == 1) {
		val= aux[0][0];
	}
	else {
		int x=0, y = 0;
		vector<vector<T>> newaux;
		for (int i = 0; i < aux.size(); i++) {
			if (i != row) {
				vector<int> cols;
				for (int j = 0; j < aux[0].size(); j++) {
					if (j != col) {
						cols.push_back(aux[i][j]);
					}
				}
				newaux.push_back(cols);
			}
		}
		
		val = getDeterminante(newaux);
	}
	return val;
}

void Matriz::calcInversa()
{
	int determinante = getDeterminante(transpuesta);
	for (int i = 0; i < transpuesta.size(); i++) {
		inversa.push_back(vector<double>());
		for (int j = 0; j < transpuesta[0].size(); j++) {
			int sum = i + j;
			inversa[i].push_back(pow(-1,(sum))*cofactor(transpuesta, i, j)/double(determinante));
		}
	}
}
template <class T>
int Matriz::getDeterminante(vector<vector<T>> matriz)
{
	int adet = 0;
	if (matriz.size() == 2) {
		adet=matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	}
	else {
		

		for (int j = 0; j < matriz[0].size(); j++) {
			int z =j;

			adet += pow(-1, z) * matriz[0][j] * cofactor(matriz,0, j);
		}
	}
	return adet;
}

void Matriz::setTranspuesta()
{
	for (vector<int> a : matriz) {
		transpuesta.push_back(vector<int>());
	}
	for (int i = 0; i < matriz.size(); i++) {
		for (int j = 0; j < matriz[0].size(); j++) {
			transpuesta[j].push_back( matriz[i][j]);
		}
	}
	
}

Matriz::Matriz()
{
}

Matriz::Matriz(vector<vector<int>> matriz)
{
	this->matriz = matriz;
	filas = matriz.size();
	columnas = matriz[0].size();
	det=getDeterminante(matriz);

	setTranspuesta();
	if(isInvertible())
		calcInversa();

}

int Matriz::getDet()
{
	return det;
}
