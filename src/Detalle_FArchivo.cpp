#pragma once
#include<iostream>
#include<cstdlib>
#include "Detalle_FArchivo.h"
#include "Detalle_Factura.h"

bool Detalle_FArchivo::guardar(Detalle_Factura df){
   bool result;
   FILE *pFile;
   pFile = fopen("detalle-factura.dat", "ab");
   if(pFile == nullptr){
        cout << "Error al guardar el registro." << endl;
        return false;
   }
   result = fwrite(&df, sizeof(Detalle_Factura), 1, pFile);
   fclose(pFile);
   return result;
}

bool Detalle_FArchivo::guardar(int index, Detalle_Factura reg){
   bool result;
   FILE *pFile;
   pFile = fopen("detalle-factura.dat", "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Detalle_Factura) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Detalle_Factura), 1, pFile);
   fclose(pFile);
   return result;
}

int Detalle_FArchivo::buscarPorFactura(int nroFactura){
    Detalle_Factura reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("detalle-factura.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Detalle_Factura), 1, pFile)){
        if(reg.getNroFactura() == nroFactura){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int Detalle_FArchivo::cantidadPorFactura(int nroFactura){
    Detalle_Factura reg;
    int cant = 0;
    FILE * pFile;
    pFile = fopen("detalle-factura.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Detalle_Factura), 1, pFile)){
        if(reg.getNroFactura() == nroFactura){
            cant++;
        }
    }
    fclose(pFile);
    return cant;
}

bool Detalle_FArchivo::getDetallesPorFactura(int nroFactura, Detalle_Factura *detalles){
    int cant = 0;
    FILE * pFile;
    pFile = fopen("detalle-factura.dat", "rb");
    if(pFile == nullptr){
        return false;
    }
    Detalle_Factura detalleFactura;
    while(fread(&detalleFactura, sizeof(Detalle_Factura), 1, pFile)){
        if(detalleFactura.getNroFactura() == nroFactura){
            detalles[cant] = detalleFactura;
            cant++;
        }
    }
    fclose(pFile);
    return true;
}

Detalle_Factura Detalle_FArchivo::leer(int index){
   bool result;
   Detalle_Factura reg;
   FILE *pFile;
   pFile = fopen("detalle-factura.dat", "rb");
   if(pFile == nullptr){
      return reg;
   }
   fseek(pFile, index * sizeof (Detalle_Factura), SEEK_SET);
   fread(&reg, sizeof(Detalle_Factura), 1, pFile);
   fclose(pFile);
   return reg;
}


int Detalle_FArchivo::getCantidadRegistros(){
   FILE *pFile;
   int tam;
   pFile = fopen("detalle-factura.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Detalle_Factura);
   fclose(pFile);
   return tam;
}

bool Detalle_FArchivo::leerTodos(Detalle_Factura *detallesFacturas) {
    int cantidad = getCantidadRegistros();

    Factura reg;
    FILE *pFile;
    pFile = fopen("detalle-factura.dat", "rb");
    if(pFile == nullptr){
      return false;
    }
    int read = fread(detallesFacturas, sizeof(Detalle_Factura), cantidad, pFile);
    fclose(pFile);
    return read != 0;
}

bool Detalle_FArchivo::createBackup() {
    bool result;
    int cantidadReg = getCantidadRegistros();

    Detalle_Factura* detallesFacturas = new Detalle_Factura[cantidadReg];

    bool canRead = leerTodos(detallesFacturas);

    if (!canRead) {
        return canRead;
    }

    FILE *pFile;
    pFile = fopen("detalle-factura.bkp", "wb");
    if(pFile == nullptr){
      return false;
    }
    fwrite(detallesFacturas, sizeof(Detalle_Factura), cantidadReg, pFile);
    fclose(pFile);
    return result;
}
