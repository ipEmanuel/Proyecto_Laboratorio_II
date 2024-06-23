#pragma once
#include <iostream>
#include<cstdlib>
using namespace std;
#include "FacturaManager.h"
#include "FacturaArchivo.h"
#include "Factura.h"
#include "Detalle_Factura.h"
#include "Detalle_FArchivo.h"
#include "AutoparteManager.h"
#include "AutoparteArchivo.h"
//#include "Cliente.h"


FacturaManager::FacturaManager(): MenuItem("Facturacion") {}

// desde el Detalle_FManager.cpp accedo a este menú

int FacturaManager::execute(){
    int option;
    do{
        system("cls");
        cout << "----------------------------------" << endl;
        cout << " ---------- MENU FACTURA ---------" << endl;
        cout << "----------------------------------" << endl;
        cout << "1- INICIAR FACTURA DE VENTA " << endl;
        cout << "2- MOSTRAR DETALLE FACTURA" << endl; //va a solicitar el ingreso de un Nro de Factura
        cout << "3- MODIFICAR DETALLE FACTURA" << endl; // va a solicitar el ingreso de un Nro de Factura para modificar su detalle
        cout << "4- ELIMINAR DETALLE FACTURA" << endl; // va a solicitar el ingreso de un Nro de Factura para eliminar -> se elimina, tambien, detalle
        cout << "5- LISTAR FACTURA DESDE-HASTA" << endl;
        cout << "----------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch(option){
            case 1:
                iniciar_factura_venta();
                system("pause");
                break;
            case 2:
                mostrar_detalle_factura();
                system("pause");
                break;
            case 3:
                //modificar_detalle_factura();
                system("pause");
                break;
            case 4:
//                eliminar_detalle_factura();
                system("pause");
                break;
            case 5:
//                listar_por_factura();
                system("pause");
            break;

        }
    }
    while(option != 0);
    return 0;
}

void FacturaManager::listar_facturas(){
    Factura f;
    FacturaArchivo fa;
    int nroFactura;
    int cantFacturas = fa.getCantidadRegistros();
    int pos=0;
    cout << "Listado de facturas: " << endl;
    while(pos < cantFacturas){
        nroFactura = fa.leer(pos).getNFactura();
        cout << nroFactura << endl;
        pos++;
    }
}


int FacturaManager::mantiene_factura(int mantiene){
    while (!(mantiene>-1 && mantiene < 2)){
        cout << "VALOR NO VALIDO. INGRESE (1-SI / 0-NO): ";
        cin >> mantiene;
    }
    return mantiene;
}


void FacturaManager::iniciar_factura_venta(){
    FacturaManager fM;
    Detalle_Factura dF;
    Detalle_FArchivo dfA;
    FacturaArchivo fA;
    Factura f;
    AutoparteArchivo aA;
    AutoparteManager aM;
    Autoparte a;

    int nroFactura, factIngresada, pos=0, mantiene, mismaFactura, idAutoparte, idCliente;
    float valorTotal=0.0f;

    nroFactura = fA.getNuevoNroFactura();
    f.setNFactura(nroFactura);
//    f.getFechaFactura().Fecha();
    do{
        int cantidad;
        cout << "NUMERO FACTURA: " << nroFactura << endl;
        cout << "1-AUTOPARTE POR ID / 0-LISTADO DE AUTOPARTES: ";
        cin >> idAutoparte;
        do{
            if(!(idAutoparte>-1 && idAutoparte<2)){
                cout << "1-AUTOPARTE POR ID / 0-LISTADO DE AUTOPARTES: ";
                cin >> idAutoparte;
            }
        }while(!(idAutoparte>-1 && idAutoparte<2));
        if(idAutoparte){
            cout << "ID AUTOPARTE: ";
            cin >> idAutoparte;
            if(aA.buscarByID(idAutoparte) > -1){
                dF.setIdAutoparte(idAutoparte);
            }
        }
        else{
            aM.listarAutoparte();
            cout << "ID AUTOPARTE: ";
            cin >> idAutoparte;
            do{
                if(!(aA.buscarByID(idAutoparte)>-1)){
                    cout << "VALOR NO VALIDO. INGRESE ID NUEVAMENTE: ";
                    cin >> idAutoparte;
                }
            }while(!(aA.buscarByID(idAutoparte)>-1));
            dF.setIdAutoparte(idAutoparte);
        }
        cout << "CANTIDAD: ";
        cin >> cantidad;
        dF.setCantidad(cantidad);
        cout << "PRECIO: " << a.getPrecioVenta() << endl;
        dF.setPrecio(a.getPrecioVenta());
        valorTotal += dF.getPrecio();
        f.setValorTotal(valorTotal);

        cout << "DESEA AGREGAR MAS AUTOPARTES (1-SI / 0-NO): ";
        cin >> mantiene;
        mismaFactura = mantiene_factura(mantiene);

    }while(mismaFactura==1);
    bool result;
    result = dfA.guardar(dF);
    if(result){
        cout << "FACTURA DE VENTA GUARDADA CON EXITO." << endl;
    }
    else{
        cout << "NO SE PUDO GUARDAR LA FACTURA DE VENTA." << endl;
    }
    cout << "ID CLIENTE: ";
    cin >> idCliente;
    f.setIdCliente(idCliente);
    result = fA.guardar(f);
    if(result){
        cout << "FACTURA GUARDADA CON EXITO." << endl;
    }
    else{
        cout << "NO SE PUDO GUARDAR LA FACTURA." << endl;
    }

//    fM.menu();

}

void FacturaManager::mostrar_detalle_factura(){
    Detalle_FArchivo dfA;
    int nFactura, nFactBuscado;

    cout << "INGRESE NUMERO DE FACTURA: ";
    cin >> nFactBuscado;
    nFactura = dfA.buscarPorFactura(nFactBuscado);
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NUMERO VALIDO: ";
            cin >> nFactBuscado;
            nFactura = dfA.buscarPorFactura(nFactBuscado);
        }
        else{
            break;
        }
    }
    dfA.leer(nFactura).mostrarDF(nFactura);

}
