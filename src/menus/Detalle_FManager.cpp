#pragma once
#include <iostream>
#include<cstdlib>
#include "Detalle_FManager.h"
#include "Detalle_FArchivo.h"
#include "Detalle_Factura.h"
#include "Factura.h"
#include "Autoparte.h"
#include "FacturaArchivo.h"
#include "FacturaManager.h"
#include "AutoparteArchivo.h"
#include "AutoparteManager.h"

//Desde la AppManager ingreso a éste menú

int Detalle_FManager::mantiene_factura(int mantiene){
    do{
        if(!(mantiene>-1 && mantiene < 2)){
            cout << "VALOR NO VALIDO. INGRESE (1-SI / 0-NO): ";
            cin >> mantiene;
        }
    }while(!(mantiene>-1 && mantiene < 2));
    return mantiene;
}


void Detalle_FManager::iniciar_factura_venta(){
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


void Detalle_FManager::modificar_detalle_factura(){
    Detalle_FArchivo dfA;
    Detalle_Factura dF, detalleF;
    int nFactura, factBuscada;

    cout << "INGRESE NUMERO DE FACTURA: ";
    cin >> factBuscada;
    nFactura = dfA.buscarPorFactura(factBuscada);

    while(!(nFactura != -1 && nFactura > 0)){
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NUMERO VALIDO: ";
            cin >> factBuscada;
            nFactura = dfA.buscarPorFactura(factBuscada);
        }
        else{
            break;
        }
    }

    cout<<"---------------------------------------------"<<endl;
    cout<<"------DATOS DE DETALLE FACTURA ACTUAL--------"<<endl;
    cout<<"---------------------------------------------"<<endl;
    dF.mostrarDF();
    cout << endl;

    if(dfA.buscarPorFactura(nFactura) != -1 && dfA.buscarPorFactura(nFactura) > 0){
        detalleF = dfA.leer(nFactura);
        dF.modificarDF(detalleF);
        if(dfA.guardar(nFactura, dF)){
            cout << "DETALLE DE FACTURA MODIFICADO CON EXITO." << endl;
        }
        else{
            cout << "NO SE PUDO MODIFICAR EL DETALLE DE FACTURA." << endl;
        }
    }
}
