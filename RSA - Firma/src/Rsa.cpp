#include "Rsa.h"
numeroAleatorio ale;
Rsa::Rsa(int bits){///Receptor
     /*
    p=conv<ZZ>("178662916409782582052283887298158139144668837797116315789099619269395655568098586286621179257120323972805232079711643028439000717001622770535789141636708089195183146285209281900813621770519966200065914297864505224461718610842505250726588640177415090839239231432672312108680834760025616689875694445041273338303");
    q=conv<ZZ>("113495129313944625431924616463655744521438995773476463151321041844816434489279552783390635801730334575835835632783135898268294081341126892997929185209875505109005838752347761410420588685046782387545442124245356414709773292892018643882248656201282114761954801578821894458632290749166104041440895144244972007339");
    e=conv<ZZ>("93143256852327905541154997250672662111591254628363132554785588965138784497734137671290648112252499847254417427895517800380514979908224171216227175519946546390917746106580710819656970760250121608762131666378389468604814416798074624061051160198354226696224926445834891783014316747545909563807660165959137908331");// */
    ///*
    p=findProbablyPrimeClosest(bits);
    q=findProbablyPrimeClosest(bits);//*/
    n=p*q;
    fiN=(p-1)*(q-1);
    ///*
    do{
        e=ale.generateAleatorio(1024);
    }while(!hayInversa(e,fiN));//*/
    d=inversa(e,fiN);
    cout<<"VALORES \nn "<<n<<"\ne "<<e<<endl;
    cout<<"p "<<p<<"\nq "<<q<<"\nfiN "<<fiN<<"\nd "<<d<<endl;
}

Rsa::Rsa(ZZ n,ZZ e){
    this->n=n;
    this->e=e;
}

string Rsa::completarCeros(string mensaje,ZZ Nr ){
    int digit =ZZtoStr(Nr).size()-1;
    int c = modint(mensaje.size(),digit);
    string cero(digit-c,'0');
    return cero+mensaje;
}

string Rsa::dividirBloques(string mensaje){
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
    return str;
}

string Rsa::cifrado(string mensajeNo,ZZ Nr,ZZ Er){
    int digit=ZZtoStr(Nr).size()-1;
    string out;
    for(int i=0;i<mensajeNo.size();i+=digit){
        ZZ p(conv<ZZ>(mensajeNo.substr(i,digit).c_str()));
        p=expModular(p,Er,Nr);
        string ceros((digit+1-ZZtoStr(p).size()),'0');
        out=out+ceros+ZZtoStr(p);
    }
    /**ofstream salida("cipherMessage.txt");
    salida<<out;
    salida.close();*/
    return out;
}

string Rsa::cifroConD(string mensajeNo){
    int digit=ZZtoStr(n).size()-1;
    string out;
    for(int i=0;i<mensajeNo.size();i+=digit){
        ZZ p(conv<ZZ>(mensajeNo.substr(i,digit).c_str()));
        p=expModular(p,d,n);
        string ceros((digit+1-ZZtoStr(p).size()),'0');
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
        ZZ c(conv<ZZ>(mensaje.substr(i,digitN).c_str()));
        c=Trc(c);
        string ceros((digit-ZZtoStr(c).size()),'0');
        salida+=ceros+ZZtoStr(c);
    }
    return salida;
    /*digit=to_string(alfabeto.size()).size();
    string outLetters;
    for(int i=0;i<salida.size();i+=digit){
        outLetters+=alfabeto.at(stoi(salida.substr(i,digit)));
    }
    return outLetters;*/
}

string Rsa::descifroConE(string mensaje,ZZ Ne,ZZ Ee){
    int a= modint(mensaje.size(),ZZtoStr(Ne).size());
    mensaje = mensaje.substr(a);
    string salida;
    int digitN=ZZtoStr(Ne).size();//S digitos
    int digit=digitN-1;
    for(int i=0;i<mensaje.size();i+=digitN){
        ZZ c(conv<ZZ>(mensaje.substr(i,digitN).c_str()));
        c=expModular(c,Ee,Ne);
        string ceros((digit-ZZtoStr(c).size()),'0');
        salida+=ceros+ZZtoStr(c);
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

ZZ Rsa::Trc(ZZ m){
    ZZ q1= inversa(mod(q,p),p);
    ZZ a1=expModular(mod(m,p),mod(d,p-1),p);//Dp,dp,p
    ZZ q2= inversa(mod(p,q),q);
    ZZ a2=expModular(mod(m,q),mod(d,q-1),q);
    return mod(mod(a1*q*q1,n)+mod(a2*p*q2,n),n);
}

string Rsa::firmarYCifrar(string mensajeL,ZZ Nr,ZZ Er){
    string aux = cifroConD(dividirBloques(mensajeL));///rubrica
    return cifrado(completarCeros(aux,Nr),Nr,Er);
}

string Rsa::defirmar(string mensaje,ZZ Ne,ZZ Ee){
    return descifroConE(descifrado(mensaje),Ne,Ee);
}
