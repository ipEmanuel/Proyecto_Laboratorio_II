#pragma once
#include "Marca.h"
class MarcaArchivo{
 public:
        void leerTodos(Marca registros[], int cantidad);
        bool guardar(Marca registro);
        bool guardar(int index, Marca registro);
        int getNuevoID();
        Marca leer(int index);
        int getCantidadRegistros();
        int buscarByID(int id);
};
