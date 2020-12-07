#ifndef BITACORA_HPP
#define BITACORA_HPP
#include <ctime>
#include <string>

using namespace std;

class Bitacora {
    
private: 
    time_t fechaHora;
    string ip;
    string razon;
    
public:
    Bitacora(time_t fechaHora, string ip, string razon);
    
    void setFechaHora(time_t fh);
    void setIp(string ip);
    void setRazon(string razon);
    
    time_t getFechaHora();
    
    friend ostream& operator<<(ostream &strm, const Bitacora &b);
    friend bool operator<(const Bitacora &b1, const Bitacora &b2);
    ~Bitacora();


};

#endif // BITACORA_HPP
