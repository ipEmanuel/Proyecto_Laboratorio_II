#pragma once
#include<iostream>
#include<cstdlib>
//using namespace std;
#include "Factura.h"
#include "FacturaArchivo.h"
#include "Autoparte.h"

bool FacturaArchivo::guardar(Factura fact){
   bool result;
   FILE *pFile;
   pFile = fopen("facturas.dat", "ab");
   if(pFile == nullptr){
        cout << "Error al guardar el registro." << endl;
        return false;
   }
   result = fwrite(&fact, sizeof (Factura), 1, pFile);
   fclose(pFile);
   return result;
}

bool FacturaArchivo::guardar(int index, Factura reg){
   bool result;
   FILE *pFile;
   pFile = fopen("facturas.dat", "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Factura) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Factura), 1, pFile);
   fclose(pFile);
   return result;
}

int FacturaArchivo::buscarPorFactura(int nroFactura){
    Factura reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("facturas.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Factura), 1, pFile)){
        if(reg.getNFactura() == nroFactura){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Factura FacturaArchivo::leer(int index){
   bool result;
   Factura reg;
   FILE *pFile;
   pFile = fopen("facturas.dat", "rb");
   if(pFile == nullptr){
      return reg;
   }
   fseek(pFile, index * sizeof (Factura), SEEK_SET);
   fread(&reg, sizeof(Factura), 1, pFile);
   fclose(pFile);
   return reg;
}


int FacturaArchivo::getCantidadRegistros(){
   FILE *pFile;
   int tam;
   pFile = fopen("facturas.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Factura);
   fclose(pFile);
   return tam;
}

int FacturaArchivo::getNuevoNroFactura(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad-1).getNFactura()+1;
    }
    else{
        return 1;
    }
}

bool FacturaArchivo::leerTodos(Factura *factura) {
    int cantidad = getCantidadRegistros();

    Factura reg;
    FILE *pFile;
    pFile = fopen("facturas.dat", "rb");
    if(pFile == nullptr){
      return false;
    }
    int read = fread(factura, sizeof(Factura), cantidad, pFile);
    fclose(pFile);
    return read != 0;
}


bool FacturaArchivo::crearBackup() {
    bool result;
    int cantidadReg = getCantidadRegistros();

    Factura* facturas = new Factura[cantidadReg];

    bool canRead = leerTodos(facturas);

    if (!canRead) {
        return canRead;
    }

    FILE *pFile;
    pFile = fopen("facturas.bkp", "wb");
    if(pFile == nullptr){
      return false;
    }
    fwrite(facturas, sizeof(Factura), cantidadReg, pFile);
    fclose(pFile);
    return result;
}
