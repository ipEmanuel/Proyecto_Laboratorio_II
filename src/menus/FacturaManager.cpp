#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#include "FacturaManager.h"
#include "FacturaArchivo.h"
#include "Factura.h"
#include "Detalle_Factura.h"
#include "Detalle_FArchivo.h"
#include "AutoparteManager.h"
#include "AutoparteArchivo.h"

#include "InformacionReporteVentas.h"

FacturaManager::FacturaManager() : MenuItem("Facturacion") {}

// desde el Detalle_FManager.cpp accedo a este men�

int FacturaManager::execute()
{
    int option;
    do
    {
        system("cls");
        cout << "----------------------------------" << endl;
        cout << " ---------- MENU FACTURA ---------" << endl;
        cout << "----------------------------------" << endl;
        cout << "1- INICIAR FACTURA DE VENTA " << endl;
        cout << "2- MOSTRAR DETALLE FACTURA" << endl;   // va a solicitar el ingreso de un Nro de Factura
        cout << "3- ELIMINAR DETALLE FACTURA" << endl;  // va a solicitar el ingreso de un Nro de Factura para eliminar -> se elimina, tambien, detalle
        cout << "4- LISTAR FACTURA DESDE-HASTA" << endl;
        cout << "----------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch (option)
        {
        case 1:
            iniciar_factura_venta();
            system("pause");
            break;
        case 2:
            mostrar_detalle_factura();
            system("pause");
            break;
        case 3:
            eliminar_detalle_factura();
            system("pause");
            break;
        case 4:
            listar_facturas();
            system("pause");
            break;
        }
    }
    while (option != 0);
    return 0;
}

void FacturaManager::eliminar_detalle_factura(){
    int nro_factura, index;
    Factura factura;
    bool eliminar;

    cout << "Ingrese id del factura: ";
    cin >> nro_factura;
    FacturaArchivo facturaArchivo;

    index = facturaArchivo.buscarPorFactura(nro_factura);

    if(index == -1){
        //cout << "No se encuentra!" << endl;
        cout << "No se encuentra!" << endl;
        return;
    }

    factura = facturaArchivo.leer(index);
    cout << "Esta seguro de que quiere eliminar esta factura con ID: " << factura.getNFactura() << "? 1-Si 0-No: ";
    cin >> eliminar;

    if(!eliminar){
        cout << "No fue eliminado!" << endl;
        return;
    }

    factura.setEstado(false);

    if(facturaArchivo.guardar(index, factura)){
        cout << "Se elimino con exito!" << endl;
    } else {
        cout << "No se pudo eliminar!" << endl;
    }
}

void FacturaManager::listar_facturas()
{
    Factura f;
    FacturaArchivo fa;
    int nroFactura;
    int cantFacturas = fa.getCantidadRegistros();

    Factura *facturas = new Factura[cantFacturas];

    fa.leerTodos(facturas);
    cout << "Listado de facturas: " << endl;
    mostrar_informe(facturas, cantFacturas);
    delete[] facturas;
}

int FacturaManager::mantiene_factura(int mantiene)
{
    while (!(mantiene > -1 && mantiene < 2))
    {
        cout << "VALOR NO VALIDO. INGRESE (1-SI / 0-NO): ";
        cin >> mantiene;
    }
    return mantiene;
}

void FacturaManager::iniciar_factura_venta()
{
    FacturaManager fM;
    Detalle_Factura detalleFactura;
    Detalle_FArchivo dfA;
    FacturaArchivo fA;
    Factura f;
    AutoparteArchivo autoparteArchivo;
    AutoparteManager aM;
    Autoparte autoparte;

    int nroFactura, factIngresada, pos = 0, mantiene, mismaFactura, idAutoparte, idCliente, idEmpleado;
    float valorTotal = 0.0f;

    nroFactura = fA.getNuevoNroFactura();
    f.setNFactura(nroFactura);
    detalleFactura.setNroFactura(nroFactura);
    cout << "NUMERO FACTURA: " << nroFactura << endl;
    cout << "ID CLIENTE: ";
    cin >> idCliente;
    f.setIdCliente(idCliente);

    cout << "ID EMPLEADO: ";
    cin >> idEmpleado;
////
    while(true){
      if (_empleadoArchivo.buscarByID(idEmpleado) != -1) {
            f.setIdEmpleado(idEmpleado);
            break; // Salir del bucle si se encontró un proveedor válido
        } else {
            cout << "ERROR: Proveedor No Valido. Intente nuevamente." << endl;
            system("pause");
           cout << "ID EMPLEADO: ";
            cin >> idEmpleado;
        }
    }

    do
    {
        int cantidad;
        cout << "1-AUTOPARTE POR ID / 0-LISTADO DE AUTOPARTES: ";
        cin >> idAutoparte;
        while (!(idAutoparte > -1 && idAutoparte < 2))
        {
            cout << "1-AUTOPARTE POR ID / 0-LISTADO DE AUTOPARTES: ";
            cin >> idAutoparte;
        }
        if (idAutoparte == 0)
        {
            aM.listarAutoparte();
        }
        cout << "ID AUTOPARTE: ";
        cin >> idAutoparte;
        int index = autoparteArchivo.buscarByID(idAutoparte);
        while (index == -1)
        {
            cout << "VALOR NO VALIDO. INGRESE ID NUEVAMENTE: ";
            cin >> idAutoparte;
        }
        detalleFactura.setIdAutoparte(idAutoparte);
        autoparte = autoparteArchivo.leer(index);

        cout << "CANTIDAD: ";
        cin >> cantidad;
        detalleFactura.setCantidad(cantidad);
        cout << "PRECIO: " << autoparte.getPrecioVenta() << endl;
        detalleFactura.setPrecio(autoparte.getPrecioVenta());
        valorTotal += (detalleFactura.getPrecio() * cantidad);
        f.setValorTotal(valorTotal);
        bool result;
        result = dfA.guardar(detalleFactura);
        if (result)
        {
            cout << "DETALLE DE VENTA GUARDADA CON EXITO." << endl;
        }
        else
        {
            cout << "NO SE PUDO GUARDAR EL DETALLE DE VENTA." << endl;
        }
        cout << "DESEA AGREGAR MAS AUTOPARTES (1-SI / 0-NO): ";
        cin >> mantiene;
        while (cin.fail() || (mantiene != 0 && mantiene != 1)) {
            cin.clear();
            cout << "DESEA AGREGAR MAS AUTOPARTES (1-SI / 0-NO): " << endl;
            cin >> mantiene;
        }

        mismaFactura = mantiene_factura(mantiene);

    }
    while (mismaFactura == 1);

    bool result = fA.guardar(f);
    if (result)
    {
        cout << "FACTURA GUARDADA CON EXITO." << endl;
    }
    else
    {
        cout << "NO SE PUDO GUARDAR LA FACTURA." << endl;
    }

    //    fM.menu();
}

void FacturaManager::mostrar_detalle_factura()
{
    FacturaArchivo facturaArchivo;
    int index, nFactBuscado;

    cout << "INGRESE NUMERO DE FACTURA: ";
    cin >> nFactBuscado;
    index = facturaArchivo.buscarPorFactura(nFactBuscado);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NUMERO VALIDO: ";
        cin >> nFactBuscado;
        index = facturaArchivo.buscarPorFactura(nFactBuscado);
    }

    Factura *facturas = new Factura[1];

    facturas[0] = facturaArchivo.leer(index);

    mostrar_informe(facturas, 1);

    delete[] facturas;
}

string fill_with(string original, char character = ' ', int length = 15)
{
    int string_length = original.length();
    if (string_length >= length)
    {
        return original;
    }

    string a = original.append(length - string_length, character);

    return a;
}

void showColumns(char separator, int column_width)
{
    string columns[8] = {"NRO FACT", "FECHA", "EMPLEADO", "AUTOPARTE", "MARCA", "PRECIO", "CANTIDAD", "TOTAL"};

    cout << separator;
    for (int i = 0; i < 8; i++)
    {
        cout << fill_with(columns[i], ' ', column_width) << separator;
    }
    cout << endl;
}

string floatTwoPresicion(float value)
{
    return to_string(value).substr(0, to_string(value).find(".") + 3);
}

void showRow(Factura factura, char separator, int column_width)
{
    InformacionReporteVentas information = InformacionReporteVentas(factura);

    int cantidad = information.getCantidadDetalles();

    for (int i = 0; i < cantidad; i++)
    {
        cout << separator;
        cout << fill_with(to_string(information.getFactura().getNFactura()));
        cout << separator;
        cout << fill_with(information.getFactura().getFechaFactura().toString());
        cout << separator;
      ///
         cout << fill_with(to_string(information.getFactura().getIdEmpleado()));
        cout << separator;
        cout << fill_with(information.getAutopartes()[i].getNombre());
        cout << separator;
        cout << fill_with(to_string(information.getAutopartes()[i].getCodMarca()));
        cout << separator;
        cout << fill_with(floatTwoPresicion(information.getAutopartes()[i].getPrecioVenta()));
        cout << separator;
        cout << fill_with(to_string(information.getDetalles()[i].getCantidad()));
        cout << separator;
        cout << fill_with(floatTwoPresicion(information.getDetalles()[i].getPrecio()));
        cout << separator << endl;
    }

}

float getTotalTodasFactura(Factura facturas[], int tam) {
    float total = 0;
    for (int i = 0;i < tam;i++) {
        if (facturas[i].getEstado()) {
            total+=facturas[i].getValorTotal();
        }
    }
    return total;
}

void FacturaManager::mostrar_informe(Factura facturas[], int tam)
{
    system("cls");

    int COLUMN_WIDTH = 15;
    char SEPARATOR = '|';
    showColumns(SEPARATOR, COLUMN_WIDTH);

    cout << fill_with("", '-', (COLUMN_WIDTH + 1) * 8) << endl;

    for (int i = 0; i < tam; i++)
    {
        if (facturas[i].getEstado()) {
            showRow(facturas[i], SEPARATOR, COLUMN_WIDTH);
        }
    }

    cout << "TOTAL: $" << getTotalTodasFactura(facturas, tam) << endl;

}
