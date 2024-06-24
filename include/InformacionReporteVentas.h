#pragma ONCE;

#include "Factura.h"
#include "Detalle_Factura.h"
#include "Empleado.h"
#include "Cliente.h"

class InformacionReporteVentas
{
    public:
        InformacionReporteVentas();
        ~InformacionReporteVentas();
        void setFactura(Factura factura);
        Factura getFactura();
        Cliente getCliente();
        Detalle_Factura* getDetalles();
        Autoparte* getAutopartes();
        int getCantidadDetalles();
        Empleado getEmpleado();

    protected:

    private:
        Factura _factura;
        int _cantidad_detalles = 0;
        Detalle_Factura *_detalle_factura;
        Autoparte *_autopartes;
        Empleado _empleado;
        Cliente _cliente;
};
