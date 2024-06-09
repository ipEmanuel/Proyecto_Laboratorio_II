#include <iostream>
using namespace std;
#include "ProveedorArchivo.h"

void ProveedorArchivo::leerTodos(Proveedor registros[], int cantidad){
   FILE *pFile = fopen("proveedores.dat", "rb");
   if(pFile == nullptr){
      cout << "Error al abrir el archivo FN Leer Todos" << endl;
      return;
   }
   fread(registros, sizeof(Proveedor), cantidad, pFile);
   fclose(pFile);
}

bool ProveedorArchivo::guardar(Proveedor reg){
   bool result;
   FILE *pFile = fopen("proveedores.dat", "ab");
   if(pFile == nullptr){
      cout << "Error al abrir el archivo FN Guardar" << endl;
      return false;
   }
   result = fwrite(&reg, sizeof (Proveedor), 1, pFile);
   fclose(pFile);
   return result;
}

bool ProveedorArchivo::guardar(int index, Proveedor reg){
   bool result;
   FILE *pFile = fopen("proveedores.dat", "rb+");
   if(pFile == nullptr){
      cout << "Error al abrir el archivo FN Guardar Index" << endl;
      return false;
   }
   fseek(pFile, sizeof(Proveedor) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Proveedor), 1, pFile);
   fclose(pFile);
   return result;
}

int ProveedorArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad - 1).getIdProveedor() + 1;
    }
    else{
        return 1;
    }
}

Proveedor ProveedorArchivo::leer(int index){
   Proveedor reg;
   FILE *pFile = fopen("proveedores.dat", "rb");
   if(pFile == nullptr){
      cout << "Error al abrir el archivo FN Leer" << endl;
      return reg;
   }
   fseek(pFile, index * sizeof (Proveedor), SEEK_SET);
   fread(&reg, sizeof(Proveedor), 1, pFile);
   fclose(pFile);
   return reg;
}

int ProveedorArchivo::getCantidadRegistros(){
   int tam;
   FILE *pFile = fopen("proveedores.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Proveedor);
   fclose(pFile);
   return tam;
}

int ProveedorArchivo::buscarByID(int id){
    Proveedor reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("proveedores.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Proveedor), 1, pFile)){
        if(reg.getIdProveedor() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
