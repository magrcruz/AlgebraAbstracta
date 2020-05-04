#include "HillCode.h"
#include "OperMatrices.h"
#include <stdlib.h>    
#include <time.h>  
HillCode::HillCode()
{
	clave = vector<vector<int>>();
}

string HillCode::cirfado(string mensaje)
{
	//arregla el tamaño del mensaje para que este enpalme al subdividirse con el orden de la clave
	mensaje = addcaracteres(mensaje);
	string coded;
	//vector q contendra cada valor que se separará del mensaje
	vector<vector<vector<int>>> parts;
	

	int pos = 0;
	int sizes = clave.matriz.size();
	vector<vector<int>> part(sizes, vector<int>(1, 0));
	//lenado de cada parte
	for(int i=1;i<=mensaje.size();i++)
	{
		part[pos][0]=alfabeto.find(mensaje[i - 1]);
		pos++;
		if (i % sizes == 0) {
			parts.push_back(part);
			pos = 0;
		}
		
	}
	OperMatrices operaciones;
	//se multiplica cada parte con la clave para obtener la clave cifrada
	for (vector<vector<int>> mat2 : parts) {
		vector<vector<int>> result =operaciones.mult(clave.matriz,mat2);
		for(vector<int> codi:result)
		{
			int pos = codi[0];
			//a cada resultado se le hall el modulo al tamaño del alfabeto
			pos = pos % alfabeto.size();
			coded+=alfabeto.at(pos);
		}
	}

	return coded;

}

string HillCode::descifrado(string mensaje)
{
	string decoded;
	vector<vector<vector<int>>> parts;

	int pos = 0;
	int sizes = clave.matriz.size();
	vector<vector<int>> part(sizes, vector<int>(1, 0));
	for (int i = 1; i <= mensaje.size(); i++)
	{
		part[pos][0]=alfabeto.find(mensaje[i - 1]);
		pos++;
		if (i % sizes == 0) {
			parts.push_back(part);
			pos = 0;
		}

	}
	OperMatrices operaciones;
	int tam = alfabeto.size();
	vector<vector<int>> newinversa = modul(clave.inversa);
	for (vector<vector<int>> mat2 : parts) {
		vector<vector<int>> result = operaciones.mult(newinversa, mat2);
		for (vector<int> codi : result)
		{
			int pos= codi[0];
			if (pos >= tam) {
				pos = pos % tam;
			}
			if (pos < 0) pos += tam;
			decoded += alfabeto.at(pos);
		}
	}
	decoded = deletecaracteres(decoded);
	return decoded;
}

HillCode::HillCode(Matriz clave)
{
	if (validarclave(clave)) this->clave = clave;
	else cout << "clave incorrecta intente otra";
}

HillCode::HillCode(int orden)
{
	clave=generarclave(orden);
}


bool HillCode::validarclave(Matriz c)
{
	//si la matriz no es invertible entonces no se puede usar como clave
	if (!c.isInvertible()) return false;
	int tam = alfabeto.size();
	if (c.getDet() < 0) return false;

	int modular = c.getDet() % tam;
	if (modular < 0) {
		modular += tam;
	}
	//si el resultado del modulo del determinante con el tamaño del alfabeto tienen divisores en común entonces no se puede usar la matriz
	//cout << "tam; " << tam << endl <<"modular" <<modular << endl;
	for (int i = 2; i <= modular; i++) {
		if (tam % i == 0 && modular % i == 0) {
			//cout <<i << endl;
			return false;
		}
	}
	
	return true;
}

vector<vector<int>> HillCode::generarclave(int orden)
{
	vector<vector<int>> c;
	bool invertibl = false;
	while (!invertibl)
	{
		vector<vector<int>> cl;
		int times = orden * orden;
		for (int i = 0; i < orden; i++) {
			cl.push_back(vector<int>());
		}
		for (int i = 0; i < cl.size(); i++) {
			for (int i = 0; i < orden; i++) {
				cl[i].push_back(0);
			}
		}
		unsigned int seed = time(NULL);
		srand(seed);
		for (int i = 0; i < orden; i++)
			for (int j = 0; j < orden; j++)
				cl[i][j] = rand() % (alfabeto.size()+1);
			

		Matriz akey(cl);

		if (validarclave(akey)) {
			invertibl = true;
			c = akey.matriz;
		}
	}
	cout << "clave:" << endl;
	clave.print<int>(c);
	return c;
}

vector<vector<int>> HillCode::modul(vector<vector<double>> tomodulate)
{
	int invmod = inversoModular();
	int tam = alfabeto.size();
	vector<vector<int>> invmodular;
	for (int i=0;i<tomodulate.size();i++) {
		vector<int> row;
		for (int j = 0; j < tomodulate[0].size();j++) {
			int data = tomodulate[i][j] * clave.getDet() * invmod;
			data = data % tam;
			if (data<0) {
				data += tam;
			}
			row.push_back(data);
		}
		invmodular.push_back(row);
	}
	return invmodular;
}

int HillCode::inversoModular()
{
	int m = alfabeto.size();
	int a = clave.getDet() %m;
	if (a < 0) a += m;
	for (int x = 1; x < m; x++)
		if ((a * x) % m == 1)
			return x;
}

string HillCode::addcaracteres(string mensaje)
{
	int dif = mensaje.size()% clave.matriz.size();
	if (dif != 0) {
		mensaje += string((clave.matriz.size()-dif), 'a');
		itemtoAddDelete = clave.matriz.size() - dif;
	}
	return mensaje;
}

string HillCode::deletecaracteres(string mensaje)
{
	string::iterator first, end;
	if (itemtoAddDelete == 0)return mensaje;
	first = mensaje.end()-itemtoAddDelete;
	end = mensaje.end();
	mensaje.erase(first, end);
	return mensaje;
}
