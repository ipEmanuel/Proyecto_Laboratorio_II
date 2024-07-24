#pragma once

#include "Factura.h"
#include "MenuItem.h"
#include "EmpleadoArchivo.h"

class FacturaManager: public MenuItem
{
    private:
        int mantiene_factura(int mantiene);
        void mostrar_informe(Factura facturas[], int tam);
        EmpleadoArchivo _empleadoArchivo;

    public:
        FacturaManager();
        int execute();
        void iniciar_factura_venta();
        void mostrar_detalle_factura();
        void listar_facturas();
        void eliminar_factura();
        void listar_por_factura();


};
