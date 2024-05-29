#pragma once
#include "Proveedor.h"
#include "ProveedorArchivo.h"

class ProveedorManager
{
    public:
         void menu();
      private:
        void agregar_proveedor();
        Proveedor crear_proveedor();
        void listar_proveedor();
        void mostrar_proveedor(Proveedor registro);
        void modificar_proveedor();
        void modificar(Proveedor &registro);
        void eliminar_proveedor();
        void listar_por_id();
        ProveedorArchivo _proveedores_archivo;
};
