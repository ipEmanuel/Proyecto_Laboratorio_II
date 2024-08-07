#pragma once
#include <iostream>
//#include <cstdlib>
#include "Detalle_FArchivo.h"
#include "Detalle_Factura.h"

Detalle_FArchivo::Detalle_FArchivo() : Archivo("detalle-factura", sizeof(Detalle_Factura)) {}

bool Detalle_FArchivo::guardar(Detalle_Factura reg)
{
    bool result = Archivo::guardar(&reg);
    return result;
}

bool Detalle_FArchivo::guardar(int index, Detalle_Factura reg)
{
    bool result = Archivo::guardar(&reg, 1, index);
    return result;
}

int Detalle_FArchivo::buscarPorFactura(int nroFactura)
{
    Detalle_Factura reg;
    int pos = 0;
    while (Archivo::leer(pos, &reg))
    {
        if (reg.getNroFactura() == nroFactura)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

int Detalle_FArchivo::cantidadPorFactura(int nroFactura)
{
    int cant = 0;

    int cantidadTodos = Archivo::getCantidadRegistros();

    for (int i = 0; i < cantidadTodos; i++)
    {
        Detalle_Factura reg;
        Archivo::leer(i, &reg, 1);
        if (reg.getNroFactura() == nroFactura)
        {
            cant++;
        }
    }

    return cant;
}

bool Detalle_FArchivo::getDetallesPorFactura(int nroFactura, Detalle_Factura *detalles)
{
    int cant = 0;
    bool result;
    int cantidadReg = getCantidadRegistros();

    Detalle_Factura *detallesFacturas = new Detalle_Factura[cantidadReg];

    bool canRead = leerTodos(detallesFacturas);

    if (!canRead)
    {
        return canRead;
    }

    for (int i = 0; i < cantidadReg; i++)
    {
        if (detallesFacturas[i].getNroFactura() == nroFactura)
        {
            //Detalle_Factura reg2 = Detalle_Factura(reg);
            detalles[cant] = detallesFacturas[i];
            cant++;
        }
    }

    delete[] detallesFacturas;

    return true;
}

Detalle_Factura Detalle_FArchivo::leer(int index)
{
    bool result;
    Detalle_Factura reg;
    Archivo::leer(index, &reg);
    return reg;
}

int Detalle_FArchivo::getCantidadRegistros()
{
    return Archivo::getCantidadRegistros();
}

bool Detalle_FArchivo::leerTodos(Detalle_Factura *registros)
{
    int cantidad = getCantidadRegistros();
    bool read = Archivo::leer(0, registros, cantidad);
    return read;
}

bool Detalle_FArchivo::createBackup()
{
    bool result;
    int cantidadReg = getCantidadRegistros();

    Detalle_Factura *detallesFacturas = new Detalle_Factura[cantidadReg];

    bool canRead = leerTodos(detallesFacturas);

    if (!canRead)
    {
        return canRead;
    }

    return Archivo::crearBackup(cantidadReg, detallesFacturas);
}

bool Detalle_FArchivo::reestablecer()
{
    bool result;
    setBackupMode(true);
    int cantidadReg = getCantidadRegistros();

    Detalle_Factura *detalles = new Detalle_Factura[cantidadReg];

    bool canRead = true;

    if (cantidadReg != 0) {
        canRead = leerTodos(detalles);
    }

    if (!canRead)
    {
        cout << "NO SE PUDO LEER EL BACKUP" << endl << cantidadReg;
        return canRead;
    }

    setBackupMode(false);

    result = Archivo::sobreescribirTodo(cantidadReg, detalles);

    return result;
}
