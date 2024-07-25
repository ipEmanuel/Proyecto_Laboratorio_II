#include <iostream>
#include "InformesManager.h"
#include "FacturaArchivo.h"
#include "Detalle_FArchivo.h"
#include <iomanip>
#include "string"
using namespace std;

InformesManager::InformesManager() : MenuItem("Informes", 2) {}

void InformesManager::mostrarPorVendedor(int legajo){
    Factura factura;
    FacturaArchivo facturaArchivo;
    int tam = facturaArchivo.getCantidadRegistros();
    int cont = 0;

    cout << "LEGAJO DEL EMPLEADO : " << legajo << endl;
    cout << left << setw(20) << "NUMERO FACTURA"
         << setw(15) << "FECHA"
         << setw(15) << "VALOR TOTAL"
         << setw(15) << "ID CLIENTE"
         << endl;

    for (int i = 0; i < tam; i++) {
        if (facturaArchivo.leerFacturaPorLegajo(i, legajo, factura)) {
            factura.mostrarFactura();
            cont += factura.getValorTotal();
        }
    }

    cout << "Valor Total: " << cont << endl;
}

void InformesManager::mostrarPorAnio(int anio){
    Factura factura;
    FacturaArchivo facturaArchivo;
    int tam = facturaArchivo.getCantidadRegistros();
    int cont = 0;

    cout << "ANIO : " << anio << endl;
    cout << left << setw(20) << "NUMERO FACTURA"
         << setw(15) << "FECHA"
         << setw(15) << "VALOR TOTAL"
         << setw(15) << "ID CLIENTE"
         << endl;

    for (int i = 0; i < tam; i++) {
        if (facturaArchivo.leerFacturaPorAnio(i, anio, factura)) {
            factura.mostrarFactura();
            cont += factura.getValorTotal();
        }
    }

    cout << "Valor Total: " << cont << endl;
}

void InformesManager::mostrarPorAutoparte(Detalle_Factura detalle){
    Factura factura;
    FacturaArchivo facturaArchivo;
    int tam = facturaArchivo.getCantidadRegistros();
    int cont = 0;

     cout << setw(16) << detalle.getNroFactura()
     << setw(15) << detalle.getIdAutoparte()
     << setw(15) << detalle.getCantidad()
     << setw(15) << detalle.getPrecio()
     << endl;

}

void InformesManager::recaudacionPorEmpleado()
{
    int legajo;
    cout<<"INGRESE EL LEGAJO DEL VENDEDOR: ";
    cin >>legajo;
    mostrarPorVendedor(legajo);
}

void InformesManager::recaudacionPorAnio()
{
    int anio;
    cout<<"INGRESE EL ANIO DEL CUAL DESEA CONOCER LA FACTURACION: ";
    cin >>anio;
    mostrarPorAnio(anio);
}

void InformesManager::recaudacionPorAutoparte()
{
    int idAutoparte, total = 0;
    cout << "INGRESE EL ID AUTOPARTE DEL CUAL DESEA CONOCER LA FACTURACION: ";
    cin >> idAutoparte;

    while (cin.fail() || idAutoparte <= 0) {
        cin.clear();
        cout << "ID AUTOPARTE. POR FAVOR INTENTE DE NUEVO." << endl;
        cin >> idAutoparte;
    }

    Detalle_FArchivo detalleArchivo;

    int cantidadDetalles = detalleArchivo.getCantidadRegistros();

    cout << setw(16) << "NUMERO DE FACTURA"
         << setw(15) << "ID AUTOPARTE"
         << setw(15) << "CANTIDAD"
         << setw(15) << "PRECIO"
         << endl;


    for (int i = 0; i < cantidadDetalles; i++) {
        Detalle_Factura detalle = detalleArchivo.leer(i);

        if (detalle.getIdAutoparte() == idAutoparte) {
            //detalle.mostrarDF();
            mostrarPorAutoparte(detalle);
            total =+ detalle.getCantidad() * detalle.getPrecio();
        }
    }

    cout << "Valor Total: " << total << endl;
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
        cout << "3- RECAUDACION POR AUTOPARTE    " << endl;
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
        case 3:
            recaudacionPorAutoparte();
            system("pause");
            break;

        }
        cout << endl;
    }
    while (option != 0);
    return 0;
}
