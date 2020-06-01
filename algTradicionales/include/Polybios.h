#ifndef POLYBIOS_H
#define POLYBIOS_H
#include <string>
using namespace std;

class Polybios
{
    public:
        Polybios();
        string cifrado(string mensaje);
        string descifrado(string mensajeCifrado);
        string alfabeto;
    protected:

    private:
};

#endif // POLYBIOS_H
