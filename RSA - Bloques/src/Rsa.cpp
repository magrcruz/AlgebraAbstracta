#include "Rsa.h"

Rsa::Rsa(int bits){///Receptor
    //ZZ p=conv<ZZ>("312434137892258267011822741607477065979");
    //ZZ q=conv<ZZ>("327733099032625485215988291068059956959");
    // /*
    ZZ p,q;
    int random=aleatorioint(10);
    ifstream archivo(to_string(bits)+"bits.txt");
    string line;
    for (int i=0;i<random;i++) getline(archivo,line);
    p= conv<ZZ>(line.c_str());
    random=aleatorioint(10);
    for (int i=0;i<random;i++) getline(archivo,line);
    q= conv<ZZ>(line.c_str());
    archivo.close();
    // */
    n=p*q;
    fiN=(p-1)*(q-1);
    //e = conv<ZZ>("3");
    do{
        e=aleatorio(n);
    }while(!hayInversa(e,fiN));
    d=inversa(e,fiN);
    cout<<"VALORES \nn "<<n<<"\ne "<<e<<endl;
    //cout<<"p "<<p<<"\nq "<<q<<"\nfiN "<<fiN<<"\nd "<<d<<endl;
}

Rsa::Rsa(ZZ n,ZZ e){
    this->n=n;
    this->e=e;
}

string Rsa::cifrado(string mensaje){
    int digit=to_string(alfabeto.size()).size();
    string str;
    string cero(digit,'0');
    for(int i=0;i<mensaje.size();i++){
        size_t pos=alfabeto.find(mensaje.at(i));
        int len=to_string(pos).size();
        if(len<digit) str+=cero.substr(0,digit-len);
        str+=to_string(pos);
    }
    digit=ZZtoStr(n).size()-1;
    while(modint(str.size(),digit)) str+="22";
    int digitN=digit+1;
    string out;
    for(int i=0;i<str.size();i+=digit){
        ZZ p(conv<ZZ>(str.substr(i,digit).c_str()));
        p=expModular(p,e,n);
        string ceros((digitN-ZZtoStr(p).size()),'0');
        out=out+ceros+ZZtoStr(p);
    }
    /**ofstream salida("cipherMessage.txt");
    salida<<out;
    salida.close();*/
    return out;
}

string Rsa::descifrado(string mensaje){
    string salida;
    int digitN=ZZtoStr(n).size();
    int digit=digitN-1;
    for(int i=0;i<mensaje.size();i+=digitN){
        ZZ q(conv<ZZ>(mensaje.substr(i,digitN).c_str()));
        q=expModular(q,d,n);
        string ceros((digit-ZZtoStr(q).size()),'0');
        salida+=ceros+ZZtoStr(q);
    }
    digit=to_string(alfabeto.size()).size();
    string outLetters;
    for(int i=0;i<salida.size();i+=digit){
        outLetters+=alfabeto.at(stoi(salida.substr(i,digit)));
    }
    return outLetters;
}

string Rsa::ZZtoStr(ZZ z){
    stringstream ss;
    ss<<z;
    return ss.str();
}
