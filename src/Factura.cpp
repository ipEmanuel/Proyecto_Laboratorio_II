#pragma once
#include <iostream>
#include "Factura.h"
#include "Cliente.h"
#include "Fecha.h"
#include "FacturaArchivo.h"
#include "FacturaManager.h"

Factura::Factura(){
    Cliente cli;
    _nFactura = 0;
    _fechaFactura = Fecha(1,1,1);
    _valorTotal = 0;
    _idCliente = cli.getIdCliente();
}

Factura::Factura(int nFactura, Fecha fechaFact, float valorTotal, int id_Cliente){
    setNFactura(nFactura);
    setFechaFactura(fechaFact);
    setValorTotal(valorTotal);
    setIdCliente(id_Cliente);
}

//getters
int Factura::getNFactura(){
    return _nFactura;
}

Fecha Factura::getFechaFactura(){
    return _fechaFactura;
}

float Factura::getValorTotal(){
    return _valorTotal;
}

int Factura::getIdCliente(){
    return _idCliente;
}


//setters
void Factura::setNFactura(int nroFactura){
    while(nroFactura<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> nroFactura;
    }
    _nFactura = nroFactura;
}

void Factura::setFechaFactura(Fecha fechaFactura){
    _fechaFactura = fechaFactura;
}

void Factura::setValorTotal(float valorTotal){
    while(valorTotal<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> valorTotal;
    }
    _valorTotal = valorTotal;
}

void Factura::setIdCliente(int idCliente){
    while(idCliente<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> idCliente;
    }
    _idCliente = idCliente;
}

//metodos

void Factura::mostrarFactura(Factura factura){
    int nroFactura;
    Fecha fecha;
    float vT;
    int idCliente;
    nroFactura = factura.getNFactura();
    cout << "Numero de factura: " << nroFactura << endl;
    fecha = factura.getFechaFactura();
    vT = factura.getValorTotal();
    cout << "Valor total: " << vT << endl;
    idCliente = factura.getIdCliente();
    cout << "ID cliente: " << idCliente << endl;
}

/*
bool Factura::crearFactura(){
    FacturaManager fM;
    FacturaArchivo fA;
    bool result;

//    result = fA.guardar(fM.creacion_factura());

    return result;
}
*/


void Factura::modificar(Factura &facturaAct){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DE FACTURA--------"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"INGRESAR NUMERO DE FACTURA: ";
    cin>>_nFactura;
    facturaAct.setNFactura(_nFactura);
    cout<<"INGRESAR FECHA: ";
    _fechaFactura.cargar();
    facturaAct.setFechaFactura(_fechaFactura);
    cout<<"INGRESAR VALOR TOTAL: $";
    cin>>_valorTotal;
    facturaAct.setValorTotal(_valorTotal);
    cout<<"INGRESAR NUMERO DE CLIETNE: ";
    cin>>_idCliente;
    facturaAct.setIdCliente(_idCliente);

}
