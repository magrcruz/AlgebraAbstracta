#include <iostream>
#include <string>
#include "Practica1.h"

using namespace std;

int main()
{
    string str1,str2,str3;
    int a, b;
/*
    //1.Convertir un objeto string a un array de tipo char, y viceversa
    cout<<endl<<"Ingrese string para convertir a array: ";
    cin>>str1;
    char arr[str1.length()];
    str1.copy(arr,str1.length());
    cout<<endl<<"Array: "<<endl;
    Practica1::printArr(arr,arr+str1.length());

    //de arreglo de chars a string
    cout<<endl<<"Char a String: "<<Practica1::charToStr(arr,sizeof(arr))<<endl;
*/
    //2.Diferencia entre la función capacity y la función size
    /**
    La funcion capacity retorna el numero de caracteres almacenables en la string que se pueden almacenar actualmente sin aumentar memoria
    La funcion size retorna el numero de caracteres almacenados actualmente en el estring
    */
/*
    //3.Convertir las letras de un string de minúsculas a mayúsculas
    str1=Practica1::mayToMin(str1);
    cout<<endl<<"Invertir min a may: "<<str1<<endl;

    //4. Concatenar dos numeros, cadena y en una nueva linea con el doble
    cout<<endl<<"Ingrese dos numeros para concatenar: "<<endl;
    cin>>a>>b;
    str1=to_string(a)+to_string(b);
    cout<<"Numeros concatenados: "<<str1<<endl;
    a=stoi(str1);
    cout<<"Doble del numero: "<<a*2<<endl;

    //5.Objeto string que esté formado por 1000 caracteres ‘a’
    string aaa(1000,'a');
    cout<<endl<<"Cadena de 1000 caracteres 'a':"<<endl;
    cout<<aaa<<endl;

    //6.Convertir la cadena a la cadena: “Yo aprobe el curso de Algebra Abstracta”
    str1="Yo desaprobe el curso de Algebra Abstracta";
    str1.erase(3,3);
    cout<<"Cadena convertida: "<<str1<<endl;

    //7.Recibir dos strings por entrada. Contar cuántas veces aparece la palabra en la frase
    cout<<"Ingrese frase: "<<endl;
    getline(cin,str1);//lee '\n'
    getline(cin,str1);
    cout<<"Ingrese palabra a contar: ";
    cin>>str2;
    cout<<"Numero de veces encontrada: ";
    cout<<Practica1::contarInStr(str1,str2)<<endl;

    //8.Recibir un string e imprimir cada letraen una nueva línea con iteradores
    cout<<"Ingrese string para dividir en lineas: "<<endl;
    getline(cin,str1);//lee '\n'
    getline(cin,str1);
    Practica1::printEnLineas(str1);

    //9.Imprimir un string que tenga al segundo string en la mitad el primer string
    cout<<"Ingrese str1: ";
    getline(cin,str1);
    cout<<"Ingrese str2: ";
    getline(cin,str2);
    str3=str1;
    str3.insert(str1.size()/2,str2);
    cout<<"Str insertada a la mitad: "<<str3<<endl<<endl;


    //10.Buscar el segundo string en el primero y reemplazarlas por el tercer string
    cout<<"Ingrese str1: ";
    getline(cin,str1);
    cout<<"Ingrese str2: ";
    getline(cin,str2);
    cout<<"Ingrese str3: ";
    getline(cin,str3);
    Practica1::buscarYremplazar(str1,str2,str3);
    cout<<"Salida: "<<str1<<endl<<endl;

    //11.Dadas dos palabras, imprimir la que es lexicográficamente mayor
    cout<<"Ingrese dos palabras: "<<endl;
    cin>>str1>>str2;
    cout<<(str1>str2?str1:str2)<<endl;

    //12.función que que escriba N números (1 a 1000) en archivo llamado “numeros.txt”
    cout<<"Ingrese cantidad de numeros: ";
    cin>>a;
    Practica1::writeNnumeros(a);

    //13.Leer los números del archivo “numeros.txt” e imprimir la sumatoria
    cout<<endl<<"Sumatoria: "<<Practica1::sumatoriaArchivo()<<endl;

//EJERCICIOS DEL LIBRO

    //18.7 Programa que cifre un mensaje usando rot13
    getline(cin,str1);//recibe'\n'
    cout<<"Ingrese mensaje a cifrar: "<<endl;
    getline(cin,str1);
    cout<<"Mensaje cifrado: "<<Practica1::cifrado(str1)<<endl;
    cout<<"Mensaje descifrado: "<<Practica1::cifrado(Practica1::cifrado(str1),0)<<endl;

*/
    /**
    Si no se conociera la clave entonces sería muy sencillo quebrantar el código ya que solo se necesitaría ir probando con cada clave
    si se hiciera manualmente podría tomar un poco de tiempo pero tarde o temprano se resolvería ya que solo hay 26 posibles claves
    (por las 26 letras), en el caso de una supercomputadora o una computadora esta operación se reduciría notablemente haciendo este
    encriptado muy sencillo de romper
    */
/*
    //18.11 programa que introduzca primer nombre y un apellido, y que concatene en una nuevo
    cout<<endl<<"Ingrese nombre y apellido en lineas separadas"<<endl;
    cin>>str1>>str2;
    string str(str1+" "+str2);
    cout<<"Cadena concatenada:"<<endl<<str<<endl;

    //18.12 Ahorcado
    Practica1::juegoAhorcado();

    //18.19 inserte los caracteres "******" en la mitad
    getline(cin,str1);// '\n'
    cout<<"Ingrese la string: "<<endl;
    getline(cin,str1);
    str1.insert(str1.size()/2,"******");
    cout<<"Cadena: "<<str1<<endl;

    //18.21 Separa en tokens
    getline(cin,str1);
    Practica1::signToToken(str1);

    //18.22 Imprimir linea al revez
    getline(cin,str1);
    string::const_reverse_iterator i=str1.rbegin();
    cout<<"Linea al revez:"<<endl;
    while(i!=str1.rend()){
        cout<<*i;
        i++;
    }

    //18.27 Escriba una versión de la rutina de ordenamiento (figura 8.28) que ordene string. Use la función swap
    a=6;
    bool seleccion;
    string arr1[a]={"lo","esencial","invisible","a","los","ojos"};
    cout<<endl<<"Orden: Ingrese (0)ascendente o (1)descendente"<<endl;
    cin>>seleccion;
    Practica1::ordenar(seleccion,arr1,a);
    Practica1::printArr(arr1,arr1+a);

    //Version 2
    int tam=6;
    int arrNumeros[]={1,24,3,5,22,65};
    string arr2[tam];
    for (int i=0;i<tam;i++) arr2[i]=to_string(arrNumeros[i]);
    Practica1::ordenarN(seleccion,arr2,tam);
    Practica1::printArr(arr2,arr2+tam);

*/

}
