#include "practica2.h"

practica2::practica2()
{
    //ctor
}

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

void practica2::getValues(bool &porConsola,string &clave,string &aDesCifrar){
    cout<<"Ingresar texto por consola? (0)no, (1)si: "<<endl;
    cin>>porConsola;
    cin.ignore();
    cout<<"Ingresar clave: "<<endl;//la clave tiene que estar incluida en el alfabeto
    getline(cin,clave);
    cout<<(porConsola?"Ingrese texto: ":"Ingrese nombre del archivo del texto: ")<<endl;
    getline(cin,aDesCifrar);
}

string practica2::insertAQUI10W4(string mensaje){
    string aqui="AQUI";
    int len=mensaje.size()+mensaje.size()/10*4;
    for (int i=10;i<len;i+=10+aqui.size())
        mensaje.insert(i,aqui);
    int aux=mensaje.size()%4;
    cout<<"len: "<<len<<endl;
    if(aux){
        string w((4-aux),'W');
        mensaje.append(w);
    }
    return mensaje;
}

string practica2::eliminarAQUI10W4(string mensaje){
    string aqui="AQUI";
    size_t finder=mensaje.find(aqui);
    while (finder!=string::npos){
        mensaje.erase(finder,aqui.size());
        finder=mensaje.find(aqui);
    }
    finder=mensaje.rfind
}
