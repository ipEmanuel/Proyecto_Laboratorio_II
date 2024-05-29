#include <iostream>
using namespace std;
#include "MarcaArchivo.h"

void MarcaArchivo::leerTodos(Marca registros[], int cantidad){
   FILE *pFile = fopen("marcas.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer Todos" << std::endl;
      return;
   }
   fread(registros, sizeof(Marca), cantidad, pFile);
   fclose(pFile);
}

bool MarcaArchivo::guardar(Marca reg){
   bool result;
   FILE *pFile = fopen("marcas.dat", "ab");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar" << std::endl;
      return false;
   }
   result = fwrite(&reg, sizeof (Marca), 1, pFile);
   fclose(pFile);
   return result;
}

bool MarcaArchivo::guardar(int index, Marca reg){
   bool result;
   FILE *pFile = fopen("marcas.dat", "rb+");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar Index" << std::endl;
      return false;
   }
   fseek(pFile, sizeof(Marca) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Marca), 1, pFile);
   fclose(pFile);
   return result;
}

int MarcaArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad - 1).getIdMarca() + 1;
    }
    else{
        return 1;
    }
}

Marca MarcaArchivo::leer(int index){
   Marca reg;
   FILE *pFile = fopen("marcas.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer" << std::endl;
      return reg;
   }
   fseek(pFile, index * sizeof (Marca), SEEK_SET);
   fread(&reg, sizeof(Marca), 1, pFile);
   fclose(pFile);
   return reg;
}

int MarcaArchivo::getCantidadRegistros(){
   int tam;
   FILE *pFile = fopen("marcas.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Marca);
   fclose(pFile);
   return tam;
}

int MarcaArchivo::buscarByID(int id){
    Marca reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("marcas.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Marca), 1, pFile)){
        if(reg.getIdMarca() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
