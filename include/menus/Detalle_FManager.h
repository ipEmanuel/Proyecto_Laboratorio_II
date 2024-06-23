#pragma once
#include "FacturaArchivo.h"
//#include "Detalle_FArchivo.h"

class Detalle_FManager
{
    private:
        void iniciar_factura_venta();
        int mantiene_factura(int mantiene);
        void mostrar_detalle_factura();
        void modificar_detalle_factura();
//        void eliminar_detalle_factura();
//        void listar_por_factura();
//        FacturaArchivo _facturaArchivo;

    public:
        void menu();

};
