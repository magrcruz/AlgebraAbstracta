#include "practica2.h"

practica2::practica2()
{
    //ctor
}

practica2::~practica2()
{
    //dtor
}
/*
string practica2::getAscii(int n){
    string base;
    for(unsigned char a=0;a<n;a++)
        base+=a;
    return base;
}
*/
void practica2::imprimirArchivo(string nombreArchivo){
    string aux;
    ifstream archivo(nombreArchivo);
    if (archivo.fail())
        cout<<"falla en abrir el archivo"<<endl;//solicitara texto en consola
    else{
        while(getline(archivo,aux))
            cout<<aux<<endl;
        cout<<endl;
    }
}

void practica2::ParaCifrarVigenere(){//genera un archivo con el texto cifrado
    bool porConsola;
    string aux;
    ofstream salida("textoCifrado.txt");

    cout<<"Ingresar por consola? (0)no, (1)si: "<<endl;
    cin>>porConsola;
    cin.ignore();
    cout<<"Ingresar clave: "<<endl;//la clave tiene que estar incluida en el alfabeto
    getline(cin,aux);
    VigenereClass algCifrado(aux);//objeto Vigenere con clave "aux"

    if (!porConsola){
        cout<<"Ingresar nombre del archivo: "<<endl;
        getline(cin,aux);
        ifstream archivo(aux);//abre archivo
        if (archivo.fail()) cout<<"falla en abrir el archivo"<<endl;//solicitara texto en consola
        else//exito en abrir el archivo
            while(getline(archivo,aux))
                salida<<algCifrado.cifrado(aux)<<endl;
    }
    else{
        cout<<"Ingrese texto para cifrar"<<endl;
        getline(cin,aux);
        salida<<algCifrado.cifrado(aux)<<endl;
    }
    cout<<endl<<"Se creo el archivo con el texto cifrado textoCifrado.txt: "<<endl;
    imprimirArchivo("textoCifrado.txt");
}

void practica2::paraDescifrarVigenere(){//genera un archivo con el texto cifrado
    bool porConsola;
    string aux;
    ofstream salida("textoDescifrado.txt");

    cout<<"Ingresar por consola? (0)no, (1)si: "<<endl;
    cin>>porConsola;
    cin.ignore();
    cout<<"Ingresar clave: "<<endl;//la clave tiene que estar incluida en el alfabeto
    getline(cin,aux);
    VigenereClass algCifrado(aux);//objeto Vigenere con clave "aux"

    if (!porConsola){
        cout<<"Ingresar nombre del archivo: "<<endl;
        getline(cin,aux);
        ifstream archivo(aux);//abre archivo
        if (archivo.fail()) cout<<"falla en abrir el archivo"<<endl;//solicitara texto en consola
        else//exito en abrir el archivo
            while(getline(archivo,aux))
                salida<<algCifrado.descifrado(aux)<<endl;
    }
    else{
        cout<<"Ingrese texto para cifrar"<<endl;
        getline(cin,aux);
        salida<<algCifrado.descifrado(aux)<<endl;
    }
    cout<<endl<<"Se creo el archivo con el texto decifrado textoCifrado.txt: "<<endl;
    imprimirArchivo("textoDescifrado.txt");
}



//Preguntas para la miss
/**
-Profesora los primeros 20 caracteres del codigo ascii son caracteres de control,
como podemos aniadirlos a la string alfabeto, consola no puede imprimir esos caracteres,
en cambio se puede rellenar su posicion con espacios?
se considera el codigo ascii extendido? (hasta el caracter 255) o se considera solo hasta el caracter 126
-Profesora en el caso del poema de Pablo Neruda se cifra linea por lines independientemente para juntar todo
o se cifra con saltos de linea
*/


