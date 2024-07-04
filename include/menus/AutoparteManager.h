#pragma once
#include "string"
#include "MenuItem.h"
#include "Autoparte.h"
#include "AutoparteArchivo.h"
#include "ProveedorArchivo.h"
#include "MarcaArchivo.h"

class AutoparteManager: public MenuItem {
    public:
        AutoparteManager();
        int execute();
        void listarAutoparte(bool ordenadoPorPrecio = false);
        bool compararNombres(const Autoparte&, const Autoparte&)const;
        void listarOrdenadoPorNombre();

    private:
        string obtenerNombreMarca(int cod_marca);
        string obtenerNombreProveedor(int id_proveedor);
        void agregarAutoparte();
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
