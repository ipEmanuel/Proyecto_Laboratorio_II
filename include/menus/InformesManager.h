#pragma once
#include "MenuItem.h"
#include "Detalle_Factura.h"

class InformesManager : public MenuItem {
    public:
        InformesManager();
        int execute();
        void recaudacionPorEmpleado();
        void recaudacionPorAnio();
        void recaudacionPorAutoparte();
        void mostrarPorVendedor(int legajo);
        void mostrarPorAnio(int anio);
        void mostrarPorAutoparte(Detalle_Factura detalle);
};
