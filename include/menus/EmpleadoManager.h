#pragma once

#include "MenuItem.h"

#include "EmpleadoArchivo.h"
#include "Empleado.h"

class EmpleadoManager: public MenuItem {
    public:
        EmpleadoManager();
        int execute();
      private:
        void agregar_empleado();
        Empleado crear_empleado();
        void listar_empleados();
        void mostrar_empleados(Empleado registro);
        void modificar_empleado();
        void modificar(Empleado &registro);
        void eliminar_empleado();
        void listar_por_id();
        EmpleadoArchivo _empleados_archivo;
};

