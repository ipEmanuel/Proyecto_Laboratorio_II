#include <iostream>
using namespace std;
#include "ClienteArchivo.h"

ClienteArchivo::ClienteArchivo(): Archivo("clientes", sizeof(Cliente)) {
}

bool ClienteArchivo::leerTodos(Cliente registros[], int cantidad){
   bool read = Archivo::leer(0, registros, cantidad);
   return read;
}

bool ClienteArchivo::guardar(Cliente reg){
   bool result = Archivo::guardar(&reg);
   return result;
}

bool ClienteArchivo::guardar(int index, Cliente reg){
   bool result = Archivo::guardar(&reg, 1, index);
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
   bool result;
   Cliente reg;
   Archivo::leer(index, &reg);
   return reg;
}

int ClienteArchivo::getCantidadRegistros(){
   return Archivo::getCantidadRegistros();
}

int ClienteArchivo::buscarByID(int id){
    Cliente reg;
    int pos = 0;
    while(Archivo::leer(pos, &reg)) {
        if(reg.getIdCliente() == id){
            return pos;
        }
        pos++;
    }
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

    return Archivo::crearBackup(cantidadReg, clientes);
}

bool ClienteArchivo::reestablecer() {
    setBackupMode(true);
    int cantidadReg = getCantidadRegistros();

    Cliente* clientes = new Cliente[cantidadReg];

    bool canRead = leerTodos(clientes, cantidadReg);

    if (!canRead) {
        cout << "NO SE PUDO LEER EL BACKUP" << endl;
        return canRead;
    }

    setBackupMode(false);

    return Archivo::sobreescribirTodo(cantidadReg, clientes);
}
