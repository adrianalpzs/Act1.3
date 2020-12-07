#include "Bitacora.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <time.h>
Bitacora::Bitacora(time_t fechaHora, string ip, string razon) {
    this->fechaHora = fechaHora;
    this->ip = ip;
    this->razon = razon;
}


void Bitacora::setFechaHora(time_t fh) {
    fechaHora = fh;
}

time_t Bitacora::getFechaHora() {
    return fechaHora;
}

void Bitacora::setIp(string ip) {
    this->ip = ip;
}

void Bitacora::setRazon(string razon) {
    this->razon = razon;
}

ostream& operator<<(ostream &os, const Bitacora &b) {
    tm ts = *std::localtime(&b.fechaHora);
    std::stringstream ss;
    os << "fecha hora: " << b.fechaHora << " " << std::put_time(&ts,"%F %T") << " ip: " << b.ip << " razón: " << b.razon << " ";
    return os;
} 

bool operator<(const Bitacora &b1, const Bitacora &b2) {
    return b1.fechaHora < b2.fechaHora;
}   

Bitacora::~Bitacora() {
}

