#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void generateSieve(int n=1000000000){
    /**
    n=1000000000 ya que es el limite de vector, encuentra primos del 2 a 2n
    cada elemento del vector desde posicion 2 representa un numero impar comenzando desde el 3
    */
    vector <bool> posiblePrimo(n,true);
    long primo=3;
    int indice= (primo*primo+1)>>1;
    for(int i=2; indice<n;){
        for(; indice<n; indice+=primo)
            posiblePrimo[indice]=false;
        while (!posiblePrimo[++i]);
        primo= (i<<1)-1;
        ///la posicion en el vector del primo
        indice= (primo*primo+1)>>1;
        ///indice es la posicion del cuadrado del numero, alli empieza a reemplazar
    }

    ofstream archivo("primos.txt");
    archivo<<2<<' ';
    for(int i=2, numero=3;i<n;i++, numero+=2){
        if(posiblePrimo[i])
            archivo<<numero<<' ';
    }
}

int main(){
    generateSieve();
    return 0;
}
