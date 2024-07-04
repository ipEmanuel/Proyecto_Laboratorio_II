#include "InformacionReporteVentas.h"
#include "iostream"
#include "Detalle_FArchivo.h"
#include "EmpleadoArchivo.h"
#include "ClienteArchivo.h"
#include "AutoparteArchivo.h"

InformacionReporteVentas::InformacionReporteVentas(Factura factura)
{
    Detalle_FArchivo detalleArchivo;

    _factura = factura;
    _cantidad_detalles = detalleArchivo.cantidadPorFactura(factura.getNFactura());

    if (_cantidad_detalles != -1 && _cantidad_detalles != 0)
    {
        _detalle_factura = new Detalle_Factura[_cantidad_detalles];
        if (_detalle_factura == nullptr) {
            cout << "ERROR AL ASIGNAR MEMORIA";
            return;
        }
        detalleArchivo.getDetallesPorFactura(factura.getNFactura(), _detalle_factura);
        _autopartes = new Autoparte[_cantidad_detalles];
        if (_autopartes == nullptr) {
            cout << "ERROR AL ASIGNAR MEMORIA";
            return;
        }

        AutoparteArchivo autoparteArchivo;
        for (int i = 0; i < _cantidad_detalles; i++)
        {
            int index = autoparteArchivo.buscarByID(_detalle_factura[i].getIdAutoparte());
            _autopartes[i] = autoparteArchivo.leer(index);
        }
    }

    EmpleadoArchivo empleadoArchivo;
    int indexEmpleado = empleadoArchivo.buscarByID(1);
    _empleado = empleadoArchivo.leer(indexEmpleado);

    ClienteArchivo clienteArchivo;
    int indexCliente = clienteArchivo.buscarByID(factura.getIdCliente());
    _cliente = clienteArchivo.leer(indexCliente);

}

InformacionReporteVentas::~InformacionReporteVentas()
{
    if (_cantidad_detalles != 0 && _cantidad_detalles != -1 && _autopartes != nullptr)
    {
        delete _autopartes;
        delete _detalle_factura;
    }
}

Factura InformacionReporteVentas::getFactura()
{
    return _factura;
}

Cliente InformacionReporteVentas::getCliente()
{
    return _cliente;
}

Detalle_Factura* InformacionReporteVentas::getDetalles()
{
    return _detalle_factura;
}

Autoparte* InformacionReporteVentas::getAutopartes()
{
    return _autopartes;
}

int InformacionReporteVentas::getCantidadDetalles()
{
    return _cantidad_detalles;
}

Empleado InformacionReporteVentas::getEmpleado()
{
    return _empleado;
}
