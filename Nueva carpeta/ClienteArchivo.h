#pragma once
#include "Cliente.h"

class ClienteArchivo
{
    public:
        void leerTodos(Cliente registros[], int cantidad);
        bool guardar(Cliente registro);
        bool guardar(int index, Cliente registro);
        int getNuevoID();
        Cliente leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);
};
