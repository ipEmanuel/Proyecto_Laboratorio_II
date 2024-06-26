#include <iostream>

using namespace std;

#include <cstring>
#include "Autoparte.h"
#include "Marca.h"

Autoparte::Autoparte()
{
   _id_autoparte = 0;
   _id_proveedor = 0;
   _precio_compra = 0.0f;
   _precio_venta = 0.0f;
   _stock = 0;
   _cod_marca = 0;
   _estado = false;
   memset(_nombre, 0, sizeof(_nombre));

}

Autoparte::Autoparte(int id_autoparte, int id_proveedor, const char* nombre, float precio_compra, float precio_venta, int stock, int cod_marca, bool estado){
   setIDAutoparte(id_autoparte);
   setIDProveedor(id_proveedor);
   setPrecioCompra(precio_compra);
   setPrecioVenta(precio_venta);
   setStock(stock);
   setCodMarca(cod_marca);
   setEstado(estado);
   setNombre(nombre);
}

// SETTERS
void Autoparte::setIDAutoparte(int id_autoparte) {
    _id_autoparte = id_autoparte;
}

void Autoparte::setIDProveedor(int id_proveedor) {
    _id_proveedor = id_proveedor;
}

void Autoparte::setNombre(string nombre) {
    if (nombre.length() < 100) {
        strcpy(_nombre, nombre.c_str());
    } else {
        strcpy(_nombre, "SIN DATOS");
    }
}

void Autoparte::setPrecioCompra(float precio_compra) {
    _precio_compra = precio_compra;
}

void Autoparte::setPrecioVenta(float precio_venta) {
    _precio_venta = precio_venta;
}

void Autoparte::setStock(int stock) {
    _stock = stock;
}

void Autoparte::setCodMarca(int cod_marca) {
    _cod_marca = cod_marca;
}

void Autoparte::setEstado(bool estado) {
    _estado = estado;
}

// GETTERS
int Autoparte::getIDAutoparte() {
    return _id_autoparte;
}

int Autoparte::getIDProveedor() {
    return _id_proveedor;
}

string Autoparte::getNombre() {
    return string(_nombre);
}

float Autoparte::getPrecioCompra() {
    return _precio_compra;
}

float Autoparte::getPrecioVenta() {
    return _precio_venta;
}

int Autoparte::getStock() {
    return _stock;
}

int Autoparte::getCodMarca() {
    return _cod_marca;
}

bool Autoparte::getEstado() {
    return _estado;
}


void Autoparte::mostrar(){
    //string nombre_marca = obtenerNombreMarca(reg.getCodMarca());
    Marca marca = _marcaArchivo.buscarMarcaById(_cod_marca);
    //string nombre_proveedor = obtenerNombreProveedor(_id_proveedor);

    cout << "CODIGO DE AUTOPARTE: " << _id_autoparte << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "PRECIO DE COMPRA: " << _precio_compra << endl;
    cout << "PRECIO DE VENTA: " << _precio_venta << endl;
    cout << "STOCK: " << _stock << endl;
    //cout << "MARCA: " << nombre_marca << endl;
    marca.mostrar();
    //cout << "PROVEEDOR: " << nombre_proveedor << endl;
    cout << "ESTADO: " << (_estado ? "Disponible": "Eliminado") << endl;
}
