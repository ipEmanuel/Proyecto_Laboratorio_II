#include <iostream>
using namespace std;
#include "ClienteArchivo.h"

bool ClienteArchivo::leerTodos(Cliente registros[], int cantidad){
   FILE *pFile = fopen("clientes.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer Todos" << std::endl;
      return false;
   }
   int readSize = fread(registros, sizeof(Cliente), cantidad, pFile);
   fclose(pFile);
   return readSize > 0;
}

bool ClienteArchivo::guardar(Cliente reg){
   bool result;
   FILE *pFile = fopen("clientes.dat", "ab");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar" << std::endl;
      return false;
   }
   result = fwrite(&reg, sizeof (Cliente), 1, pFile);
   fclose(pFile);
   return result;
}

bool ClienteArchivo::guardar(int index, Cliente reg){
   bool result;
   FILE *pFile = fopen("clientes.dat", "rb+");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar Index" << std::endl;
      return false;
   }
   fseek(pFile, sizeof(Cliente) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Cliente), 1, pFile);
   fclose(pFile);
   return result;
}

int ClienteArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad - 1).getIdCliente() + 1;
    }
    else{
        return 1;
    }
}

Cliente ClienteArchivo::leer(int index){
   Cliente reg;
   FILE *pFile = fopen("clientes.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer" << std::endl;
      return reg;
   }
   fseek(pFile, index * sizeof (Cliente), SEEK_SET);
   fread(&reg, sizeof(Cliente), 1, pFile);
   fclose(pFile);
   return reg;
}

int ClienteArchivo::getCantidadRegistros(){
   int tam;
   FILE *pFile = fopen("clientes.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Cliente);
   fclose(pFile);
   return tam;
}

int ClienteArchivo::buscarByID(int id){
    Cliente reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("clientes.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Cliente), 1, pFile)){
        if(reg.getIdCliente() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

bool ClienteArchivo::crearBackup() {
    bool result;
    int cantidadReg = getCantidadRegistros();

    Cliente* clientes = new Cliente[cantidadReg];

    bool canRead = leerTodos(clientes, cantidadReg);

    if (!canRead) {
        return canRead;
    }

    FILE *pFile;
    pFile = fopen("clientes.bkp", "wb");
    if(pFile == nullptr){
      return false;
    }
    fwrite(clientes, sizeof(Cliente), cantidadReg, pFile);
    fclose(pFile);
    return result;
}

