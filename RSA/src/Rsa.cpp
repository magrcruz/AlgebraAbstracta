#include "Rsa.h"

Rsa::Rsa()
{///Receptor
    //ZZ p(479909),q(479939);
    ZZ p=ZZ(17), q=ZZ(43);
    n=p*q;
    ZZ fiN=(p-1)*(q-1);
    /*do{
        e=MathZZ::aleatorio(n);
    }while(!MathZZ::hayInversa(e,fiN));*/
    e=101;
    d=MathZZ::inversa(e,fiN);
    cout<<"n "<<n<<" e "<<e<<endl;
}

Rsa::Rsa(ZZ n,ZZ e){
    this->n=n;
    this->e=e;
}

void Rsa::cifrado(string mensaje){
    ofstream salida("cipherMessage.txt");
    for(int i=0;i<mensaje.size();i++){
        ZZ p= ZZ(alfabeto.find(mensaje.at(i)));
        salida<<MathZZ::expModular(p,e,n)<<'\n';
    }
    salida.close();
}


void Rsa::cifrado(){
    ifstream in("message.txt");
    ofstream out("cipherMessage.txt");
    string line;
    while(getline(in,line)){
        ZZ p = conv<ZZ>(line.c_str());
        out<<MathZZ::expModular(p,e,n)<<'\n';
    }
    in.close();
    out.close();
}

void Rsa::descifrado(){
    ifstream in("cipherMessage.txt");
    ofstream out("decipherMessage.txt");
    string line;
    while(getline(in,line)){
        ZZ q = conv<ZZ>(line.c_str());
        out<<MathZZ::expModular(q,d,n)<<'\n';
    }
    in.close();
    out.close();
}

void Rsa::numbersLetters(){
    ifstream in("decipherMessage.txt");
    string line;
    while(getline(in,line)){
        int q = stoi(line);
        cout<<alfabeto.at(q);
    }
    in.close();
}
