#pragma once
#include "string"
#include <cstring>
#include "ProveedorArchivo.h"
#include "MarcaArchivo.h"
#include "Fecha.h"

class Autoparte{
    private:
        int _id_autoparte;
        int _id_proveedor;
        char _nombre[100];
        float _precio_compra;
        float _precio_venta;
        int _stock;
        int _cod_marca;
        bool _estado;
        MarcaArchivo _marcaArchivo;
        ProveedorArchivo _proveedorArchivo;

    public:
        Autoparte();
        Autoparte(int id_autoparte, int id_proveedor, const char* nombre, float precio_compra, float precio_venta, int stock, int cod_marca, bool estado);

        void mostrar();

        // Setters
        void setIDAutoparte(int id_autoparte);
        void setIDProveedor(int id_proveedor);
        void setNombre(string nombre);
        void setPrecioCompra(float precio_compra);
        void setPrecioVenta(float precio_venta);
        void setStock(int stock);
        void setCodMarca(int cod_marca);
        void setEstado(bool estado);

        // Getters
        int getIDAutoparte();
        int getIDProveedor();
        const char* getNombre() const;
        float getPrecioCompra();
        float getPrecioVenta();
        int getStock();
        int getCodMarca();
        bool getEstado();
};
