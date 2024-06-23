#pragma once
#include "Fecha.h"
#include "Cliente.h"
using namespace std;

class Factura {
    private:
        int _nFactura;
        Fecha _fechaFactura;
        float _valorTotal;
        int _idCliente;
        bool _estado;

    public:
        Factura();
        Factura(int nFactura, Fecha fechaFact, float valorTotal, int id_Cliente);

        //getters
        int getNFactura();
        Fecha getFechaFactura();
        float getValorTotal();
        int getIdCliente();

        //setters
        void setNFactura(int nroFactura);
        void setFechaFactura(Fecha f);
        void setValorTotal(float valorTotal);
        void setIdCliente(int cli);

        //metodos
        void mostrarFactura(Factura factura);
        void modificar(Factura &facturaAct);
};
