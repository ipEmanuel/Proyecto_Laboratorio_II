#pragma once
#include "Factura.h"
#include "Detalle_Factura.h"
#include "Archivo.h"

class Detalle_FArchivo : public Archivo
{
private:
public:
    Detalle_FArchivo();
    bool guardar(Detalle_Factura df);
    bool guardar(int index, Detalle_Factura reg);
    int buscarPorFactura(int nroFactura);
    int cantidadPorFactura(int nroFactura);
    bool getDetallesPorFactura(int nroFactura, Detalle_Factura *detalles);
    Detalle_Factura leer(int index);
    int getCantidadRegistros();
    bool leerTodos(Detalle_Factura *detalle_factura);
    bool createBackup();
    bool reestablecer();
};
