#include <iostream>
#include "InformesManager.h"
#include "FacturaArchivo.h"
using namespace std;

InformesManager::InformesManager() : MenuItem("Informes", 2) {}

void InformesManager::recaudacionPorEmpleado()
{
    int legajo;
    cout<<"INGRESE EL LEGAJO DEL VENDEDOR: ";
    cin >>legajo;
    FacturaArchivo facturaArchivo;
    facturaArchivo.mostrarPorVendedor(legajo);
}

void InformesManager::recaudacionPorAnio()
{
    int anio;
    cout<<"INGRESE EL ANIO DEL CUAL DESEA CONOCER LA FACTURACION: ";
    cin >>anio;
    FacturaArchivo facturaArchivo;
    facturaArchivo.mostrarPorAnio(anio);
}

int InformesManager::execute()
{
    int option;
    do
    {
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "-------- MENU INFORMES ---------" << endl;
        cout << "--------------------------------" << endl;
        cout << "1- RECAUDACION POR EMPLEADOS    " << endl;
        cout << "2- RECAUDACION POR ANIO         " << endl;
        cout << "________________________________" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            recaudacionPorEmpleado();
            system("pause");
            break;

        case 2:
            recaudacionPorAnio();
            system("pause");
            break;

        }
        cout << endl;
    }
    while (option != 0);
    return 0;
}
