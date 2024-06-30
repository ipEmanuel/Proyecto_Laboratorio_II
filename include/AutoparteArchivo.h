#pragma once
#include "Autoparte.h"
#include "Archivo.h"

class AutoparteArchivo: public Archivo {
    public:
        AutoparteArchivo();
        bool leerTodos(Autoparte registros[], int cantidad);
        bool guardar(Autoparte registro);
        int getNuevoID();
        Autoparte leer(int index);
        int getCantidadRegistros();
        bool guardar(int index, Autoparte registro);

        /// devuelva el indice
        int buscarByID(int id);

        // int modificar(int id, Autoparte reg);
        // int modificar(int idex, Autoparte reg);
        bool crearBackup();
        bool reestablecer();
    private:
};

