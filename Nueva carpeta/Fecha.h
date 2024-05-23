#pragma once
#include <ctime>
#include <string>

class Fecha {
private:
    int dia, mes, anio;
public:
    ///constructor
    Fecha() {
       /* time_t t = time(nullptr);
        tm* fS = localtime(&t);
        dia = fS->tm_mday;
        mes = fS->tm_mon + 1;
        anio = fS->tm_year + 1900;*/

        time_t t = time(nullptr);
        struct tm fS;
        localtime_s(&fS, &t);
        dia = fS.tm_mday;
        mes = fS.tm_mon + 1;
        anio = fS.tm_year + 1900;

    }
    Fecha(int d, int m, int a){
        dia = d;
        mes = m;
        anio = a;
    }
    ///metodos
    std::string toString();
    bool fechaValida(int d, int m, int a);
    bool anioBisiesto(int a);
    void cargar();
    void mostrar();

    ///sets
    void setDia(int x) { dia = x; }
    void setMes(int x) { mes = x; }
    void setAnio(int x) { anio = x; }
    ///gets
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }

};
