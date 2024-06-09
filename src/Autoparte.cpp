#include <iostream>
using namespace std;
#include <cstring>
#include "Autoparte.h"

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

void Autoparte::setNombre(const char* nombre) {
    if (std::strlen(nombre) < sizeof(_nombre)) {
        std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
    } else {
        std::strncpy(_nombre, "SIN DATOS", sizeof(_nombre) - 1);
        _nombre[sizeof(_nombre) - 1] = '\0';
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

const char* Autoparte::getNombre() {
    return _nombre;
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


