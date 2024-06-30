#pragma once
#include <iostream>
#include "Autoparte.h"
#include "Factura.h"

class FacturaArchivo
{
    private:


    public:
        bool guardar(Factura fact);
        bool guardar(int index, Factura reg);
        Factura leer(int index);
        int getCantidadRegistros();
        int getNuevoNroFactura();
        int buscarPorFactura(int nroFactura);
        Factura recorreArchivoFacturas();
        bool leerTodos(Factura *facturas);
        bool crearBackup();
};
