#pragma once
#include <iostream>
#include <cstdlib>
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
    Detalle_Factura reg;
    int cant = 0, pos = 0;
    FILE *pFile;
    while (Archivo::leer(pos, &reg))
    {
        if (reg.getNroFactura() == nroFactura)
        {
            cant++;
        }
        pos++;
    }
    return cant;
}

bool Detalle_FArchivo::getDetallesPorFactura(int nroFactura, Detalle_Factura *detalles)
{
    int cant = 0, pos = 0;
    Detalle_Factura reg;
    while (Archivo::leer(pos, &reg))
    {
        if (reg.getNroFactura() == nroFactura)
        {
            detalles[cant] = reg;
            cant++;
        }
        pos++;
    }
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

    bool canRead = leerTodos(detalles);

    if (!canRead)
    {
        cout << "NO SE PUDO LEER EL BACKUP" << endl;
        return canRead;
    }

    setBackupMode(false);

    Archivo::sobreescribirTodo(cantidadReg, detalles);

    return result;
}
