#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"
class ClienteManager{
      public:
         void menu();
      private:
        void agregar_cliente();
        Cliente crear_cliente();
        void listar_clientes();
        void mostrar_clientes(Cliente registro);
        void modificar_cliente();
        void modificar(Cliente &registro);
        void eliminar_cliente();
        void listar_por_id();
        ClienteArchivo _clientes_archivo;
};

