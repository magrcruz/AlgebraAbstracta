#ifndef AFIN_H
#define AFIN_H
#include <string>
#include "Mates.h"

using namespace std;

class Afin{
    public:
        Afin();
        Afin (int a, int b);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    protected:

    private:
        void generarClaves();
        int a, b, invA;
};

#endif // AFIN_H
