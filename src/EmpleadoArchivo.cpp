#include <iostream>
using namespace std;
#include "EmpleadoArchivo.h"

bool EmpleadoArchivo::leerTodos(Empleado registros[], int cantidad){
   FILE *pFile = fopen("empleados.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer Todos" << std::endl;
      return false;
   }
   int readSize = fread(registros, sizeof(Empleado), cantidad, pFile);
   fclose(pFile);
   return readSize > 0;
}

bool EmpleadoArchivo::guardar(Empleado reg){
   bool result;
   FILE *pFile = fopen("empleados.dat", "ab");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar" << std::endl;
      return false;
   }
   result = fwrite(&reg, sizeof (Empleado), 1, pFile);
   fclose(pFile);
   return result;
}

bool EmpleadoArchivo::guardar(int index, Empleado reg){
   bool result;
   FILE *pFile = fopen("empleados.dat", "rb+");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Guardar Index" << std::endl;
      return false;
   }
   fseek(pFile, sizeof(Empleado) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Empleado), 1, pFile);
   fclose(pFile);
   return result;
}

int EmpleadoArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad - 1).getIdEmpleado() + 1;
    }
    else{
        return 1;
    }
}

Empleado EmpleadoArchivo::leer(int index){
   Empleado reg;
   FILE *pFile = fopen("empleados.dat", "rb");
   if(pFile == nullptr){
      std::cout << "Error al abrir el archivo FN Leer" << std::endl;
      return reg;
   }
   fseek(pFile, index * sizeof (Empleado), SEEK_SET);
   fread(&reg, sizeof(Empleado), 1, pFile);
   fclose(pFile);
   return reg;
}

int EmpleadoArchivo::getCantidadRegistros(){
   int tam;
   FILE *pFile = fopen("empleados.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Empleado);
   fclose(pFile);
   return tam;
}

int EmpleadoArchivo::buscarByID(int id){
    Empleado reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("empleados.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Empleado), 1, pFile)){
        if(reg.getIdEmpleado() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

bool EmpleadoArchivo::createBackup() {
    bool result;
    int cantidadReg = getCantidadRegistros();

    Empleado* empleados = new Empleado[cantidadReg];

    bool canRead = leerTodos(empleados, cantidadReg);

    if (!canRead) {
        return canRead;
    }

    FILE *pFile;
    pFile = fopen("empleados.bkp", "wb");
    if(pFile == nullptr){
      return false;
    }
    fwrite(empleados, sizeof(Empleado), cantidadReg, pFile);
    fclose(pFile);
    return result;
}
