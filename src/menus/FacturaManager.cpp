#pragma once
#include <iostream>
#include<cstdlib>
using namespace std;
#include "FacturaManager.h"
#include "FacturaArchivo.h"
#include "Factura.h"
//#include "Cliente.h"

/**
FacturaManager::FacturaManager()
{

}
*/

// desde el Detalle_FManager.cpp accedo a este menú

void FacturaManager::menu(){
    int option;
    do{
        system("cls");
        cout << "----------------------------------" << endl;
        cout << "---------- MENU FACTURA --------- " << endl;
        cout << "----------------------------------" << endl;
        cout << "1- CREAR FACTURA " << endl;
        cout << "2- MODIFICAR FACTURA" << endl;
        cout << "3- LISTAR FACTURAS" << endl;
        cout << "4- ELIMINAR FACTURA" << endl;
        cout << "5- LISTAR POR FACTURA" << endl;
        cout << "----------------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch(option){
            case 1:
                creacion_factura();
                system("pause");
                break;
            case 2:
                modificar_factura();
                system("pause");
                break;
            case 3:
                listar_facturas();
                system("pause");
                break;
            case 4:
//                eliminar_factura();
                system("pause");
                break;
            case 5:
//                listar_por_factura();
                system("pause");
            break;

        }
    }
    while(option != 0);
}

void FacturaManager::creacion_factura(){
    Factura factura;
    int nroFactura, idCliente;
    Fecha fechaFactura;
    float valorTotal;
    Cliente cli;
    FacturaArchivo fa;
    bool result;

    nroFactura = fa.getNuevoNroFactura();
    cout << "Numero de factura: " << nroFactura <<endl;
    factura.setNFactura(nroFactura);
    cout << "Fecha de factura: " <<endl;
    fechaFactura.cargar();
    fechaFactura.mostrar();
    factura.setFechaFactura(fechaFactura);
    cout << "Valor total de factura: ";
    cin >> valorTotal;
    factura.setValorTotal(valorTotal);
    cout << "Numero de cliente: ";
    cin >> idCliente;
    cli.setIdCliente(idCliente);

    result = fa.guardar(factura);
    system("cls");
    if(result){
        cout << "FACTURA CREADA CON EXITO." << endl;
    }
    else{
        cout << "NO SE PUDO CREAR LA FACTURA." << endl;
    }

}

void FacturaManager::modificarFactura(){
    Factura facturaAct;
    FacturaArchivo fa;
    Factura f;
    int nroFact, nroF;
    bool result;

    cout<<"-------------------------------------------"<<endl;
    cout<<"------NUMERO DE FACTURA A MODIFICAR--------"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"INGRESAR NUMERO DE FACTURA: ";
    cin>>nroF;
    facturaAct.setNFactura(nroF);
    nroFact = facturaAct.getNFactura();
    facturaAct = fa.leer(nroFact);
    cout << endl;
    cout << "DATOS DE FACTURA ACTUAL: " << endl;
    f.mostrarFactura(facturaAct);
    cout << endl;
    f.modificar(facturaAct);
    cout << endl;
    cout << "DATOS DE FACTURA MODIFICADA:" << endl;
    f.mostrarFactura(facturaAct);
    if(fa.guardar(nroFact, facturaAct)){
        cout << "FACTURA MODIFICADA CON EXITO." << endl;
    }
    else{
        cout << "NO SE PUDO MODIFICAR LA FACTURA." << endl;
    }

}

void FacturaManager::modificar_factura(){

    system("cls");
    modificarFactura();

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
