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
    _fechaFactura = Fecha();
    _valorTotal = 0;
    _idCliente = cli.getIdCliente();
}

Factura::Factura(int nFactura, Fecha fechaFact, float valorTotal, int id_Cliente, int idEmpleado){
    setNFactura(nFactura);
    setFechaFactura(fechaFact);
    setValorTotal(valorTotal);
    setIdCliente(id_Cliente);
    setIdEmpleado(idEmpleado);
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

int Factura::getIdEmpleado() {
    return _idEmpleado;
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

void Factura::setIdEmpleado(int idEmpleado) {
    _idEmpleado = idEmpleado;
}


//metodos

void Factura::mostrarFactura(){
    int nroFactura;
    Fecha fecha;
    float vT;
    int idCliente;
    nroFactura = getNFactura();
    cout << "Numero de factura: " << nroFactura << endl;
    fecha = getFechaFactura();
    vT = getValorTotal();
    cout << "Valor total: " << vT << endl;
    idCliente = getIdCliente();
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
