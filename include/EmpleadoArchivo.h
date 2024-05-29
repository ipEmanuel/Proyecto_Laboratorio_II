#pragma once
#include "Empleado.h"

class EmpleadoArchivo
{
   public:
        void leerTodos(Empleado registros[], int cantidad);
        bool guardar(Empleado registro);
        bool guardar(int index, Empleado registro);
        int getNuevoID();
        Empleado leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);


};
