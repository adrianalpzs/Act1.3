/*
Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)

Adriana López A01656937
Mariana Muñoz A01653166

El codigo almacena datos de un vector, de tal manera que un usuario puede buscar fechas y almacenarlas dentro de un vector nuevo. Se ocuparon algoritmos de ordenamiento y busqueda
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Bitacora.hpp"

vector<Bitacora> cargaBitacora(string archivo);
vector<Bitacora> getFechaHora();

/*
Ordenamiento burbuja (bubblesort)
n*(n+1)/2
Mejor de los casos:0
Peor de los casos:n*(n+1)/2
Como una burbuja que asciende por ser liviana, tomando el valor proximo comparandolo y dejando el valor mas liviano arriba

*/
void ordenaBurbuja(vector<Bitacora>& b){
  bool swap= true;
  int par = b.size();
  while(swap){
    par--;
    swap= false;
    for( int i=0; i< par; i++){
      if(b.at(i) < b.at(i+1)){
        Bitacora tmp =b.at(i);
        b.at(i)=b.at(i+1);
        b.at(i+1)= tmp;
        swap=true;
      }
    }
  }
}
/* 
Busqueda Binaria
Mejor de los casos:O(1)
Peor de los casos:O(logn)
  Encontrar dividiendo a la mitad consecutivamente hasta encontrar solo una ubicación posible 

*/
int busqBinaria(vector<Bitacora> &b, int e) {
    int medio, izq, der;
    izq=0;
    der=b.size()-1;
    if (e<b.at(izq).getFechaHora()){
      return izq;
    }else if (e >b.at(der).getFechaHora()){
      return der+1;
    }
    while (izq <= der) {
      medio=(izq+der)/2;
        if (e < b.at(medio).getFechaHora()){
            izq = medio + 1;
        }else if (b.at(medio).getFechaHora()){
          der=medio-1;
        } else{
          return medio;
        }
    }
    
}

/*
Función ocupada para el almacenamiento de los datos seleccionados 
*/
void guarda(vector<Bitacora>& b, string archivo, int inicio, int  fin, int fechaF){
  ofstream f;
  f.open(archivo);
  int c = 0;
  if(fechaF > b.at(b.size()-1).getFechaHora() || fechaF != b.at(fin).getFechaHora()){
    c = fin-1;
  } else {
    c = fin;
  }
  int g = c;
  while(inicio <= g){
    cout <<b.at(g)<<endl;
    f << b.at(g) << endl;
    g--;
  }
  f.close();
}


int main() {
  std::cout << "Hello World!\n";
  int p1, p2;
  string mes,dia,tiempo, m2, d2, t2;
  tm ts, ts2;

  vector<Bitacora> bitacora = cargaBitacora("bitacoraNueva.txt");
  /*Ordene la información por fecha para la realización de las búsquedas.*/
  ordenaBurbuja(bitacora);
/* Solicite al usuario las fechas de inicio y fin de búsqueda de información.*/
cout << "Fecha de inicio: " << endl;
  cin >> mes >> dia >> tiempo;
  ts.tm_isdst = 1;
  string tss = "2019 " + mes + " " + dia + " " + tiempo; 
  strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
  time_t fechaHoraInicio = mktime(&ts);
  p1 = busqBinaria(bitacora, fechaHoraInicio);
  cout << p1 << endl;
  cout << "Fecha de fin: " << endl;
  cin >> m2 >> d2 >> t2;
  ts.tm_isdst = 1;
  string tss2 = "2019 " + m2 + " " + d2 + " " + t2; 
  strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
  time_t fechaHoraFin = mktime(&ts);
  p2 = busqBinaria(bitacora, fechaHoraFin);
  cout << p2 << endl;
  /*
Despliegue los registros correspondientes a esas fechas.*/
cout<<p1<<p2<<endl;
 /*Almacenar en un archivo el resultado del ordenamiento.*/
 guarda(bitacora, "bitacoraNueva.txt", p1,p2, fechaHoraFin);
}
