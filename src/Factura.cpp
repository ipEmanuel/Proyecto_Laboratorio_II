#pragma once
#include <iostream>
#include <iomanip>

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
    _estado = true;
}

Factura::Factura(int nFactura, Fecha fechaFact, float valorTotal, int id_Cliente, int idEmpleado){
    setNFactura(nFactura);
    setFechaFactura(fechaFact);
    setValorTotal(valorTotal);
    setIdCliente(id_Cliente);
    setIdEmpleado(idEmpleado);
    setEstado(true);
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

bool Factura::getEstado() {
    return _estado;
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

void Factura::setEstado(bool estado) {
    _estado = estado;
}


//metodos

void Factura::mostrarFactura(){
    int nroFactura;
    Fecha fecha;
    float vT;
    int idCliente;

    nroFactura = getNFactura();
    fecha = getFechaFactura();
    vT = getValorTotal();
    idCliente = getIdCliente();


     cout << left << setw(20) << nroFactura
     << setw(15) << fecha.toString()
     << setw(15) << vT
     << setw(15) << idCliente
     << endl;

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
    cout<<"INGRESAR NUMERO DE CLIENTE: ";
    cin>>_idCliente;
    facturaAct.setIdCliente(_idCliente);


}
