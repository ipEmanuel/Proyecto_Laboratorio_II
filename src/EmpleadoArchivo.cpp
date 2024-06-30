#include <iostream>
using namespace std;
#include "EmpleadoArchivo.h"

EmpleadoArchivo::EmpleadoArchivo(): Archivo("empleados", sizeof(Empleado)) {
}

bool EmpleadoArchivo::leerTodos(Empleado registros[], int cantidad){
   bool read = Archivo::leer(0, registros, cantidad);
   return read;
}

bool EmpleadoArchivo::guardar(Empleado reg){
   bool result = Archivo::guardar(&reg);
   return result;
}

bool EmpleadoArchivo::guardar(int index, Empleado reg){
   bool result = Archivo::guardar(&reg, 1, index);
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
    bool result;
    Archivo::leer(index, &reg);
    return reg;
}

int EmpleadoArchivo::getCantidadRegistros(){
    return Archivo::getCantidadRegistros();
}

int EmpleadoArchivo::buscarByID(int id){
    Empleado reg;
    int pos = 0;
    while(Archivo::leer(pos, &reg)) {
        if(reg.getIdEmpleado() == id){
            return pos;
        }
        pos++;
    }
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

    return Archivo::crearBackup(cantidadReg, empleados);
}

bool EmpleadoArchivo::reestablecer() {
    bool result;
    setBackupMode(true);
    int cantidadReg = getCantidadRegistros();

    Empleado* empleados = new Empleado[cantidadReg];

    bool canRead = leerTodos(empleados, cantidadReg);

    if (!canRead) {
        cout << "NO SE PUDO LEER EL BACKUP" << endl;
        return canRead;
    }

    setBackupMode(false);

    Archivo::sobreescribirTodo(cantidadReg, empleados);

    return result;
}
