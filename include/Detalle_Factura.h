#pragma once
#include "Autoparte.h"
#include "AutoparteArchivo.h"

class Detalle_Factura
{
    private:
        int _nroFactura;
        int _idAutoparte;
        int _cantidad;
        float _precio;
        AutoparteArchivo _autoparteArchivo;

    public:
        //GETTERS
        int getNroFactura();
        int getIdAutoparte();
        int getCantidad();
        float getPrecio();

        //SETTERS
        void setNroFactura(int nroFactura);
        void setIdAutoparte(int idAutoparte);
        void setCantidad(int cantidad);
        void setPrecio(float precio);


        //METODOS
        Detalle_Factura crearDF();
        void mostrarDF(int nroFactura);
        void modificarDF(Detalle_Factura &dF);

};
