#pragma once
#include <iostream>
#include "Factura.h"
#include "Archivo.h"

class FacturaArchivo : public Archivo
{
public:
    FacturaArchivo();
    bool guardar(Factura fact);
    bool guardar(int index, Factura reg);
    Factura leer(int index);
    int getCantidadRegistros();
    int getNuevoNroFactura();
    int buscarPorFactura(int nroFactura);
    Factura recorreArchivoFacturas();
    bool leerTodos(Factura *facturas);
    bool crearBackup();
    bool reestablecer();
    int getCantidadFacturasPorLegajo(int legajo);
    bool leerFacturasPorLegajo(Factura *facturas, int legajo);
    ////////////////////////
    bool leerFacturaPorLegajo(int index, int legajo, Factura &factura);
    void mostrarPorVendedor(int legajo);
};
