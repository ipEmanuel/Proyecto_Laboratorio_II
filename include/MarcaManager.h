#pragma once
#include "Marca.h"
#include "MarcaArchivo.h"
class MarcaManager{
public:
    void menu();
    private:
        Marca crear_marca();
        void listar_marcas();
        void agregar_marca();
        void mostrar_marcas(Marca reg);
        void eliminar_marca();
        void listar_por_id();
        void modificar_marca();
        void modificar(Marca &registro);
        MarcaArchivo _marcas_archivo;
};
