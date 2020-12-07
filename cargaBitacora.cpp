#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "Bitacora.hpp"

vector<Bitacora> cargaBitacora(string archivo) {
    vector<Bitacora> bitacora;
    ifstream f;
    string mes, dia, tiempo;
    f.open(archivo);
    for(int i = 0; i < 500; i++) {
    //while(!f.eof()) {
        getline(f, mes, ' ');
        getline(f, dia, ' ');
        getline(f, tiempo, ' ');
        tm ts;
        ts.tm_isdst = 1;
        string tss = "2019 " + mes + " " + dia + " " + tiempo; 
        strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
        //ts.tm_year = 119;
        time_t fechaHora = mktime(&ts);
        string ip;
        getline(f, ip, ' ');
        string razon;
        getline(f, razon);
        Bitacora b(fechaHora, ip, razon);
        bitacora.push_back(b);
    }
    return bitacora;
}