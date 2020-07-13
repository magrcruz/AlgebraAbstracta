#include "numeroAleatorio.h"

void numeroAleatorio::fillWithMemoryInfo() {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {//obtiene los procesos en aProcesses
        cProcesses = cbNeeded / sizeof(DWORD);// Calcula cuantos procesos fueron retornados
        for (int i = 100; i < cProcesses; i++){
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i]);
            if (NULL != hProcess){
                PROCESS_MEMORY_COUNTERS pmc;
                if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
                    processInfo+=(to_string(pmc.PageFaultCount)+to_string(pmc.WorkingSetSize)+
                    to_string(pmc.QuotaPagedPoolUsage)+to_string(pmc.QuotaNonPagedPoolUsage)+to_string(pmc.PeakPagefileUsage));
                }
            }
            CloseHandle(hProcess);
        }
    }
}
vector<int> numeroAleatorio::generateSeed(){
    if((processInfo.size()<contador+15)||processInfo.empty()){
        processInfo.clear();
        fillWithMemoryInfo();
        contador=0;
    }
    vector<int> k;
    for(int i=0, j=contador;i<5;i++,j+=3){
        int n=stoi(processInfo.substr(j,3));
        while(n>255) n>>=1;
        while(n<128) n<<=1;
        k.push_back(n);
    }
    contador+=15;
    return k;
}
int numeroAleatorio::modint(int a,int n){
    int q=a/n;
    if(q<0) q--;
    return a-(n*q);
}
vector<bool> numeroAleatorio::initialize(vector<int> semilla){
    vector<int> Or;
    {//permite que S solo pertenezca a este scope
    vector<int> S;
    for(int i=0;i<256;i++) S.push_back(i);
    {//permite que k solo exista en este scope, optimiza memoria
        vector<int> K;
        for(int i=0,k=0;i<=51;i++)
            for(int j=0;j<5;j++,k++)
                K.push_back(semilla[j]);
        for(int i=0,f=0;i<256;i++){
            f=modint(f+S[i]+K[i],256);
            swap(S[i],S[f]);
        }
    }
    for(int i=0,f=0,k=0;k<8;k++){
        i=modint(i+1,256);
        f=modint(f+S.at(i),256);
        swap(S.at(i),S.at(f));
        Or.push_back(S.at(modint(S.at(i)+S.at(f),256)));//t
    }
    }
    vector<bool> out;
    for(int i=0;i<8;i++){
        bitset<8> aux(Or[i]);
        for(int j=0;j<8;j++)
            out.push_back(aux[j]);
    }
    return out;
}

void numeroAleatorio::izqRotate(vector<bool> &vec, int times){
    vec.insert(vec.end(),vec.begin(),vec.begin()+times);
    vec.erase(vec.begin(),vec.begin()+times);
}

//no son necesarias multiples copias de estos valores

vector<bool> numeroAleatorio::DES(int bits){
    vector<bool> K;//para guardar todas las k
    {
    vector<bool>k=initialize(generateSeed());
    int nBits=bits/48+1;
    vector<bool> c; vector<bool> d;
    for(int i=0;i<28;i++) c.push_back(k.at(PC_1[i]));
    for(int i=28;i<56;i++) d.push_back(k.at(PC_1[i]));
    for(int i=0;i<nBits;i++){
        izqRotate(c,rotaciones[i]);
        izqRotate(d,rotaciones[i]);
        vector<bool> both(c.begin(),c.end());
        both.insert(both.end(),d.begin(),d.end());
        for(int i=0;i<48;i++) K.push_back(both.at(PC_2[i]));
    }
    }
    K.resize(bits);
    K[0]=1; K[bits-1]=1;
    return K;
}

ZZ numeroAleatorio::conversion(vector<bool> vec){
    ZZ salida(0);
    ZZ i(1);
    for(vector<bool>::reverse_iterator it=vec.rbegin();it!=vec.rend();++it){
        if(*it) salida+=i;
        i<<=1;
    }
    return salida;
}

ZZ numeroAleatorio::generateAleatorio(int bits){
    return conversion(DES(bits));
}

bool millerRabinOdd(ZZ n,int nVeces){
    if(mod(n,ZZ(2))==ZZ(0)) return false;
    if(mod(n,ZZ(3))==ZZ(0)) return false;
    if(mod(n,ZZ(5))==ZZ(0)) return false;
    if(mod(n,ZZ(7))==ZZ(0)) return false;
    if(mod(n,ZZ(11))==ZZ(0)) return false;
    if(mod(n,ZZ(13))==ZZ(0)) return false;
    if(mod(n,ZZ(17))==ZZ(0)) return false;
    if(mod(n,ZZ(19))==ZZ(0)) return false;
    if(mod(n,ZZ(23))==ZZ(0)) return false;
    int firstPrimes[]={2,3,5,7,11,13,17,19,23};
    ZZ m = n-1;
    long k=0;
    while(mod(n,ZZ(2))==0){
        m>>=1;
        k++;
    }
    while(nVeces--){
        ZZ a(firstPrimes[nVeces-1]);
        ZZ t(expModular(a,m,n));
        if(t==ZZ(1)||t==ZZ(n-1))//es probablemente primo
            continue;//probablemente primo
        long j=1;
        while(j<k){
            t=expModular(t,ZZ(2),n);
            if(t==ZZ(1)||t!=n-1) return false;
            j++;
        }
        if(t!=n-1) return false;
    }
    return true;
}
numeroAleatorio al;

ZZ findProbablyPrimeClosest(int bits){
    ZZ n=al.generateAleatorio(bits);
    ZZ a=mod(n,ZZ(6));
     n-=a+ZZ(5); //para obtener la forma 6n+5
     if(millerRabinOdd(n,9)) return n;
     else{
        while(true){
            n+=2;
            if(millerRabinOdd(n,9)) return n;
            n+=4;
            if(millerRabinOdd(n,9)) return n;
        }
     }
}

/**
Los numeros primos tienen la forma de 6n+1 o 6n+5
http://jlbase.com/index.php/2020/04/18/create-large-random-prime-with-golang/
https://mae.ufl.edu/~uhk/NEAREST-PRIME.pdf
*/
