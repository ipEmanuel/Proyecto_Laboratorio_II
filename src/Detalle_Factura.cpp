#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;
#include "Detalle_Factura.h"
#include "AutoparteArchivo.h"
#include "Detalle_FArchivo.h"

/*
Detalle_Factura::Detalle_Factura(int nroFactura, int idAutoparte, int cantidad, float precio)
{
    setNroFactura(nroFactura);
    setIdAutoparte(idAutoparte);
    setCantidad(cantidad);
    setPrecio(precio);
}
*/

Detalle_Factura::Detalle_Factura() {}

Detalle_Factura::Detalle_Factura(const Detalle_Factura& otro) {
    _nroFactura = otro._nroFactura;
    _idAutoparte = otro._idAutoparte;
    _cantidad = otro._cantidad;
    _precio = otro._precio;
}

Detalle_Factura::~Detalle_Factura() {
    //cout << this << " D " << endl << this->getNroFactura() << getIdAutoparte() << endl;
    //system("pause");
}

//GETTERS
int Detalle_Factura::getNroFactura(){
    return _nroFactura;
}

int Detalle_Factura::getIdAutoparte(){
    return _idAutoparte;
}

int Detalle_Factura::getCantidad(){
    return _cantidad;
}

float Detalle_Factura::getPrecio(){
    return _precio;
}


//SETTERS
void Detalle_Factura::setNroFactura(int nroFactura){
    while(nroFactura<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> nroFactura;
    }
    _nroFactura = nroFactura;
}


void Detalle_Factura::setIdAutoparte(int idAutoparte){
    while(idAutoparte<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> idAutoparte;
    }
    _idAutoparte = idAutoparte;
}

void Detalle_Factura::setCantidad(int cantidad){
    while(cantidad<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> cantidad;
    }
    _cantidad = cantidad;
}

void Detalle_Factura::setPrecio(float precio){
    while(precio<0){
        cout << "VALOR INVALIDO. INTENTE NUEVAMENTE." << endl;
        cin >> precio;
    }
    _precio = precio;
}

void Detalle_Factura::mostrarDF(){
    cout << "NUMERO DE FACTURA: " << getNroFactura() << endl;
    cout << "ID AUTOPARTE: " << getIdAutoparte() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "PRECIO: " << getPrecio() << endl;
}

void Detalle_Factura::modificarDF(Detalle_Factura &dF){
    Detalle_FArchivo dfA;
    AutoparteArchivo autoparteArchivo;
    int idAutoparte, nFactura;

    cout<<"-------------------------------------------------"<<endl;
    cout<<"------DATOS DE DETALLE FACTURA A MODIFICAR-------"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"NUMERO DE FACTURA: ";
    cin>>_nroFactura;
    nFactura = dfA.buscarPorFactura(_nroFactura);
    while(!(nFactura != -1 && nFactura > 0)){
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NUMERO VALIDO: ";
            cin >> _nroFactura;
            nFactura = dfA.buscarPorFactura(_nroFactura);
        }
        else{
            break;
        }
    }
//    dfA.leer(nFactura).getNroFactura();
    dfA.leer(nFactura).setNroFactura(nFactura);

    cout<<"INGRESAR ID AUTOPARTE: ";
    cin>>_idAutoparte;
    idAutoparte = autoparteArchivo.buscarByID(_idAutoparte);
    while(!(idAutoparte != -1 && idAutoparte > 0)){
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NUMERO VALIDO: ";
            cin >> _idAutoparte;
            idAutoparte = autoparteArchivo.buscarByID(_idAutoparte);
        }
        else{
            break;
        }
    }

    if(idAutoparte != -1 && idAutoparte > 0){
        dF.setIdAutoparte(idAutoparte);
    }

    cout<<"INGRESE CANTIDAD: ";
    cin>>_cantidad;
    dF.setCantidad(_cantidad);
    cout<<"INGRESE PRECIO: $";
    cin>>_precio;
    dF.setPrecio(_precio);

}
