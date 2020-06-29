#include <iostream>
#include <vector>
#include <windows.h>
#include <psapi.h>

using namespace std;

void getProcessInfo(DWORD processID, vector <unsigned long>& a);
void fillWithMemoryInfo(vector <unsigned long> &k, int maxElementos);
void fillWithRandomPtrInfo(vector <unsigned long> &k, int maxElementos);

void generateSeed(vector <unsigned long> &k, int maxElementos) {
    fillWithMemoryInfo(k, maxElementos);
    fillWithRandomPtrInfo(k, maxElementos);
}///funcion principal genera la semilla

int main(void)
{
    vector <unsigned long> k;//vector que contendra la semilla
    generateSeed(k, 256);
    for (int i = 0; i < 256; i++) cout << k.at(i) << endl;
    return 0;
    //El tam del vector dependera de la capacidad de la memoria
    //un vector de tipo unsigned long se debe a la definicion de DWORD(unsigned long), cada miembro de PROCESS_MEMORY_COUNTERS es un DWORD
}

void getProcessInfo(DWORD processID, vector <unsigned long>& a) {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
    PROCESS_MEMORY_COUNTERS pmc;
    if (NULL == hProcess) return;
    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
        a.push_back(pmc.PageFaultCount);
        a.push_back(pmc.WorkingSetSize);
        a.push_back(pmc.QuotaPagedPoolUsage);
        a.push_back(pmc.QuotaNonPagedPoolUsage);
        a.push_back(pmc.PeakPagefileUsage);
    } // Agrega al vector parametros del Proceso
    CloseHandle(hProcess);
}
void fillWithMemoryInfo(vector <unsigned long> &k, int maxElementos) {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {//obtiene los procesos en aProcesses
        cProcesses = cbNeeded / sizeof(DWORD);// Calcula cuantos procesos fueron retornados
        for (int i = 0; i < cProcesses, k.size()+5<=maxElementos; i++) getProcessInfo(aProcesses[i], k);
    }
}

void fillWithRandomPtrInfo(vector <unsigned long>& k, int maxElementos) {
    const unsigned long* ptr = new unsigned long;
    delete ptr;//genera un dangling pointer
    while (k.size() < maxElementos) {
        if (*ptr != 0) k.push_back(*ptr);//Trabaja con basura del sistema para llenar lo que quede del vector
        ptr++;
    }
    //No todos los compiladores permiten la lectura, Visual lanza Exception thrown: read access violation. Utilizo codeblocks
}
