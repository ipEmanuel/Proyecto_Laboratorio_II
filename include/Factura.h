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
        int _idEmpleado;
        bool _estado;

    public:
        Factura();
        Factura(int nFactura, Fecha fechaFact, float valorTotal, int id_Cliente, int idEmpleado);

        //getters
        int getNFactura();
        Fecha getFechaFactura();
        float getValorTotal();
        int getIdCliente();
        int getIdEmpleado();
        bool getEstado();

        //setters
        void setNFactura(int nroFactura);
        void setFechaFactura(Fecha f);
        void setValorTotal(float valorTotal);
        void setIdCliente(int cli);
        void setIdEmpleado(int idEmpleado);
        void setEstado(bool estado);

        //metodos
        void mostrarFactura();
        void modificar(Factura &facturaAct);
};
