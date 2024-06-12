#pragma once
#include "MenuItem.h"
#include "Autoparte.h"
#include "AutoparteArchivo.h"
#include "ProveedorArchivo.h"
#include "MarcaArchivo.h"

class AutoparteManager: public MenuItem {
    public:
        AutoparteManager();
        int execute();
    private:
        char* obtenerNombreMarca(int cod_marca);
        char* obtenerNombreProveedor(int id_proveedor);
        void agregarAutoparte();
        void listarAutoparte(bool ordenadoPorPrecio = false);
        Autoparte crearAutoparte();
        void volverCargarAutoparte(Autoparte &registro);
        void mostrarAutoparte(Autoparte registro);
        void modificarAutoparte();
        void eliminarAutoparte();
        void ordenarAutopartesPorPrecioVenta(Autoparte *autopartes, int cantidad);

        AutoparteArchivo _autopartesArchivo;
        ProveedorArchivo _proveedorArchivo;
        MarcaArchivo _marcaArchivo;

};
