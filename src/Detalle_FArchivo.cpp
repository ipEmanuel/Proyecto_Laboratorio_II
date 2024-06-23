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
   result = fwrite(&df, sizeof (Detalle_Factura), 1, pFile);
   fclose(pFile);
   return result;
}

bool Detalle_FArchivo::guardar(int index, Detalle_Factura reg){
   bool result;
   FILE *pFile;
   pFile = fopen("detalle-facturas.dat", "rb+");
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
    pFile = fopen("detalle-facturas.dat", "rb");
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

/*
int Detalle_FArchivo::getNuevoNroFactura(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad-1).getNFactura()+1;
    }
    else{
        return 1;
    }
}
*/
