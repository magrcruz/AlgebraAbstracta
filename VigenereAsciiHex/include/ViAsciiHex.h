#ifndef VIASCIIHEX_H
#define VIASCIIHEX_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class ViAsciiHex
{
    public:
        ViAsciiHex(string clave,bool Ascii=1);
        virtual ~ViAsciiHex();
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        vector<string> alfabeto={"wNULLw","wSOHw","wSTXw","wETXw","wEOTw","wENQw","wACKw","wBELw","wBSw","wHTw","wLFw","wVTw","wFFw","wCRw","wSOw","wSIw","wDLEw","wDC1w","wDC2w","wDC3w","wDC4w","wNAKw","wSYNw","wETBw","wCANw","wEMw","wSUBw","wESCw","wFSw","wGSw","wRSw","wUSw"," ","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/","0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?","@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","^","_","´","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","wDELw","Ç","ü","é","â","ä","à","å","ç","ê","ë","è","ï","î","ì","Ä","Å","É","æ","Æ","ô","ö","ò","û","ù","ÿ","Ö","Ü","¢","£","¥","₧","ƒ","á","í","ó","ú","ñ","Ñ","ª","º","¿","⌐","¬","½","¼","¡","«","»","░","▒","▓","│","┤","╡","╢","╖","╕","╣","║","╗","╝","╜","╛","┐","└","┴","┬","├","─","┼","╞","╟","╚","╔","╩","╦","╠","═","╬","╧","╨","╤","╥","╙","╘","╒","╓","╫","╪","┘","┌","█","▄","▌","▐","▀","α","ß","Γ","π","Σ","σ","µ","τ","Φ","Θ","Ω","δ","∞","φ","ε","∩","≡","±","≥","≤","⌠","⌡","÷","≈","°","∙","·","√","ⁿ","²","■"};
        string leerTxt(string nombreArchivo);
        string descifradoSumas(string nombreArchivo);
    protected:

    private:

        //vector<string> strToVecStr(string str);
        void crearArchivo(string mensaje);
        string clave;
        size_t find(vector<string> vec,string buscando);
        size_t inicioAlfabeto=32;

};


#endif // VIASCIIHEX_H
