#pragma once
#include "Proveedor.h"
class ProveedorArchivo{
    public:
        void leerTodos(Proveedor registros[], int cantidad);
        bool guardar(Proveedor registro);
        bool guardar(int index, Proveedor registro);
        int getNuevoID();
        Proveedor leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);
        Proveedor buscarProveedorById(int id);
};
