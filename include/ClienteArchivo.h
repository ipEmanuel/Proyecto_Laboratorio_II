#pragma once
#include "Cliente.h"
#include "Archivo.h"

class ClienteArchivo: public Archivo
{
    public:
        ClienteArchivo();
        bool leerTodos(Cliente registros[], int cantidad);
        bool guardar(Cliente registro);
        bool guardar(int index, Cliente registro);
        int getNuevoID();
        Cliente leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);
        bool crearBackup();
        bool reestablecer();

    private:
        string _archivo_nombre;
};
