#pragma once
#include "Matriz.h"
#include "OperMatrices.h"
#include <string>
#include <iostream>
using namespace std;
class HillCode
{
	public:
		//abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.
		string alfabeto= "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
		HillCode(Matriz);
		HillCode(int);
		HillCode();
		Matriz clave;
		string cirfado(string);
		string descifrado(string);
	private:
		bool validarclave(Matriz);
		vector<vector<int>> generarclave(int);
		vector<vector<int>> modul(vector<vector<double>>);
		int inversoModular();
		int itemtoAddDelete;
		string addcaracteres(string);
		string deletecaracteres(string);
};

