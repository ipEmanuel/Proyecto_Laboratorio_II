#pragma once
#include "Empleado.h"

class EmpleadoArchivo
{
   public:
        bool leerTodos(Empleado registros[], int cantidad);
        bool guardar(Empleado registro);
        bool guardar(int index, Empleado registro);
        int getNuevoID();
        Empleado leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);
        bool createBackup();
};
