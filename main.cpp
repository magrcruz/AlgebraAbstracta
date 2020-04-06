#include <iostream>
#include <string>
#include "Practica1.h"

using namespace std;

int main()
{
    string primero,segundo,tercero;
    string str1;
//1.Convertir un objeto string a un array de tipo char, y viceversa
    /*string str;
    cout<<endl<<"Ingrese string para convertir a array: ";
    cin>>str;
    char arr[str.length()];
    str.copy(arr,str.length());
    cout<<endl<<"Array: "<<endl;
    Practica1::printArr(arr,arr+str.length());

    //de arreglo de chars a string
    cout<<endl<<"Char a String: "<<Practica1::charToStr(arr,sizeof(arr))<<endl;
*/
//2.Diferencia entre la función capacity y la función size
    /**
    La funcion capacity retorna el numero de caracteres almacenables en la string que se pueden almacenar actualmente sin aumentar memoria
    La funcion size retorna el numero de caracteres almacenados actualmente en el estring
    */

//3.Convertir las letras de un string de minúsculas a mayúsculas
   /* str=Practica1::mayToMin(str);
    cout<<endl<<"Invertir min a may: "<<str<<endl;

//4. Concatenar dos numeros, cadena y en una nueva linea con el doble
    int a, b;
    cout<<endl<<"Ingrese dos numeros para concatenar: "<<endl;
    cin>>a>>b;
    str=to_string(a)+to_string(b);
    cout<<"Numeros concatenados: "<<str<<endl;
    int out=stoi(str);
    cout<<"Doble del numero: "<<out*2<<endl;

//5.Objeto string que esté formado por 1000 caracteres ‘a’
    string aaa(1000,'a');
    cout<<endl<<"Cadena de 1000 caracteres 'a':"<<endl;
    cout<<aaa<<endl;

//6.Convertir la cadena a la cadena: “Yo aprobe el curso de Algebra Abstracta”
    string aprobar="Yo desaprobe el curso de Algebra Abstracta";
    aprobar.erase(3,3);
    cout<<"Cadena convertida: "<<aprobar<<endl;

//7.Recibir dos strings por entrada. Contar cuántas veces aparece la palabra en la frase
    string frase, palabra;
    cout<<"Ingrese frase: "<<endl;
    getline(cin,frase);//lee '\n'
    getline(cin,frase);
    cout<<"Ingrese palabra a contar: ";
    cin>>palabra;
    cout<<"Numero de veces encontrada: ";
    cout<<Practica1::contarInStr(frase,palabra)<<endl;

//8.Recibir un string e imprimir cada letraen una nueva línea con iteradores
    string enLinea;
    cout<<"Ingrese string para dividir en lineas: "<<endl;
    getline(cin,enLinea);//lee '\n'
    getline(cin,enLinea);
    Practica1::printEnLineas(enLinea);

//9.Imprimir un string que tenga al segundo string en la mitad el primer string
    string primera, segunda,tercera;
    cout<<"Ingrese str1: ";
    getline(cin,primera);
    cout<<"Ingrese str2: ";
    getline(cin,segunda);
    tercera=primera;
    tercera.insert(primera.size()/2,segunda);
    cout<<"Str insertada a la mitad: "<<tercera<<endl<<endl;


//10.Buscar el segundo string en el primero y reemplazarlas por el tercer string
    cout<<"Ingrese str1: ";
    getline(cin,primera);
    cout<<"Ingrese str2: ";
    getline(cin,segunda);
    cout<<"Ingrese str3: ";
    getline(cin,tercera);
    Practica1::buscarYremplazar(primera,segunda,tercera);
    cout<<"Salida: "<<primera<<endl<<endl;

//11.Dadas dos palabras, imprimir la que es lexicográficamente mayor
    cout<<"Ingrese dos palabras: "<<endl;
    cin>>primera>>segunda;
    cout<<(primera>segunda?primera:segunda)<<endl;

//12.función que que escriba N números (1 a 1000) en archivo llamado “numeros.txt”
    int n;
    cout<<"Ingrese cantidad de numeros: ";
    cin>>n;
    Practica1::writeNnumeros(n);

//13.Leer los números del archivo “numeros.txt” e imprimir la sumatoria
    cout<<"Sumatoria: "<<Practica1::sumatoriaArchivo()<<endl;
    return 0;
    */
//EJERCICIOS DEL LIBRO
//18.7 -18.11 -18.12 -18.19 -18.21 -18.22 -18.27

//18.7 Programa que cifre un mensaje usando rot13
/*    getline(cin,str1);
    cout<<"Ingrese mensaje a cifrar: "<<endl;
    getline(cin,str1);
    str1=Practica1::cifrado(str1);
    cout<<"Mensaje cifrado: "<<str1<<endl;
    cout<<"Mensaje descifrado: "<<Practica1::cifrado(str1,0);

*/
    /**
    Si no se conociera la clave entonces sería muy sencillo quebrantar el código ya que solo se necesitaría ir probando con cada clave
    si se hiciera manualmente podría tomar un poco de tiempo pero tarde o temprano se resolvería ya que solo hay 26 posibles claves
    (por las 26 letras), en el caso de una supercomputadora o una computadora esta operación se reduciría notablemente haciendo este
    encriptado muy sencillo de romper
    */

//18.11 programa que introduzca primer nombre y un apellido, y que concatene en una nuevo
/*    cout<<endl<<"Ingrese nombre y apellido en lineass separadas"<<endl;
    cin>>primero>>segundo;
    tercero=(primero+" "+segundo);
    cout<<"Cadena concatenada:"<<endl<<tercero<<endl;
*/

//18.12 Ahorcado
    Practica1::juegoAhorcado();
    return 0;
}
