#include "Fecha.h"
#include <iostream>

bool Fecha::anioBisiesto(int a) {

    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return true;
    else return false;

}

bool Fecha::fechaValida(int d, int m, int a) {

   if (a < 1900) {
        std::cout << "ERROR: ANIO DEBE SER MAYOR O IGUAL QUE 1500" << std::endl;
        return false;
    }
    if (m < 1 || m > 12) {
        std::cout << "ERROR: MES DEBE ESTAR ENTRE 1 Y 12" << std::endl;
        return false;
    }
    if (d < 1 || d > 31) {
        std::cout << "ERROR: DIA DEBE ESTAR ENTRE 1 Y 31" << std::endl;
        return false;
    }

    // Días máximos según el mes
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        std::cout << "ERROR: EL MES " << m << " TIENE MAXIMO 30 DIAS" << std::endl;
        return false;
    }
    if (m == 2) {
        if (anioBisiesto(a) && d > 29) {
            std::cout << "ERROR: FEBRERO TIENE MAXIMO 29 DIAS EN UN ANIO BISIESTO" << std::endl;
            return false;
        } else if (!anioBisiesto(a) && d > 28) {
            std::cout << "ERROR: FEBRERO TIENE MAXIMO 28 DIAS EN UN ANIO NO BISIESTO" << std::endl;
            return false;
        }
    }

    // Sla fecha máxima válida es el 31 de diciembre de 2999
    if (a > 2999 || (a == 2999 && m == 12 && d > 31)) {
        std::cout << "ERROR: LA FECHA NO PUEDE SER MAYOR AL 31 DE DICIEMBRE DE 2999" << std::endl;
        return false;
    }

    // La fecha es válida
    return true;
}

void Fecha::cargar() {

    int d, m, a;
    bool check = false;

    while (check == false) {

        std::cout << "DIA: ";
        std::cin >> d;
        std::cout << "MES: ";
        std::cin >> m;
        std::cout << "ANIO: ";
        std::cin >> a;
        check = fechaValida(d, m, a);
    }
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::mostrar() {
    std::cout << dia << "/" << mes << "/" << anio << std::endl;
}

std::string Fecha::toString() {
  return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

