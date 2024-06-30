#pragma once
#include <iostream>
#include <cstdlib>
#include "Factura.h"
#include "FacturaArchivo.h"

FacturaArchivo::FacturaArchivo() : Archivo("facturas", sizeof(Factura)) {}

bool FacturaArchivo::guardar(Factura reg)
{
    bool result = Archivo::guardar(&reg);
    return result;
}

bool FacturaArchivo::guardar(int index, Factura reg)
{
    bool result = Archivo::guardar(&reg, 1, index);
    return result;
}

int FacturaArchivo::buscarPorFactura(int nroFactura)
{
    Factura reg;
    int pos = 0;
    while (Archivo::leer(pos, &reg))
    {
        if (reg.getNFactura() == nroFactura)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

Factura FacturaArchivo::leer(int index)
{
    bool result;
    Factura reg;
    Archivo::leer(index, &reg);
    return reg;
}

int FacturaArchivo::getCantidadRegistros()
{
    return Archivo::getCantidadRegistros();
}

int FacturaArchivo::getNuevoNroFactura()
{
    int cantidad = getCantidadRegistros();
    if (cantidad > 0)
    {
        return leer(cantidad - 1).getNFactura() + 1;
    }
    else
    {
        return 1;
    }
}

bool FacturaArchivo::leerTodos(Factura *registros)
{
    int cantidad = getCantidadRegistros();

    bool read = Archivo::leer(0, registros, cantidad);
    return read;
}

bool FacturaArchivo::crearBackup()
{
    bool result;
    int cantidadReg = getCantidadRegistros();

    Factura *facturas = new Factura[cantidadReg];

    bool canRead = leerTodos(facturas);

    if (!canRead)
    {
        return canRead;
    }

    return Archivo::crearBackup(cantidadReg, facturas);
}

bool FacturaArchivo::reestablecer()
{
    bool result;
    setBackupMode(true);
    int cantidadReg = getCantidadRegistros();

    Factura *facturas = new Factura[cantidadReg];

    bool canRead = leerTodos(facturas);

    if (!canRead)
    {
        cout << "NO SE PUDO LEER EL BACKUP" << endl;
        return canRead;
    }

    setBackupMode(false);

    Archivo::sobreescribirTodo(cantidadReg, facturas);

    return result;
}