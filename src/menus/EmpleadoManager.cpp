#include <iostream>

using namespace std;

#include "EmpleadoManager.h"

EmpleadoManager::EmpleadoManager(): MenuItem("Empleados", 2) {}

int EmpleadoManager::execute(){
    int option;
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "----- MENU DE EMPLEADOS ------ " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR EMPLEADO " << endl;
        cout << "2- LISTAR" << endl;
        cout << "3- MODIFICAR " << endl;
        cout << "4- ELIMINAR" << endl;
        cout << "5- LISTAR POR ID" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;
        switch(option){
            case 1:
                agregar_empleado();
                system("pause");
                break;
            case 2:
                listar_empleados();
                system("pause");
                break;
            case 3:
                modificar_empleado();
                system("pause");
                break;
            case 4:
                eliminar_empleado();
                system("pause");
                break;
            case 5:
                listar_por_id();
                system("pause");
            break;
        }
    }while(option != 0);
    return 0;
}

Empleado EmpleadoManager::crear_empleado(){
    Empleado nuevo_empleado;
    int id = _empleados_archivo.getNuevoID();
    nuevo_empleado.setIdEmpleado(id);
    nuevo_empleado.cargar(id);
    return nuevo_empleado;
}

void EmpleadoManager::agregar_empleado(){
    if(_empleados_archivo.guardar(crear_empleado()))    {
        cout << "El empleado fue guardado con exito!" << endl;
    }else{
        cout << "No se pudo guardar el empleado!" << endl;
    }
}

void EmpleadoManager::listar_empleados(){
    int cantidad = _empleados_archivo.getCantidadRegistros();
    Empleado *empleados;
    empleados = new Empleado[cantidad];
    if(empleados == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _empleados_archivo.leerTodos(empleados, cantidad);
    for(int i=0; i<cantidad; i++){
        if(empleados[i].getEstado()){
            cout << "--------------------------" << endl;
            mostrar_empleados(empleados[i]);
            cout << "--------------------------" << endl;
        }
    }
    delete [] empleados;
}

void EmpleadoManager::mostrar_empleados(Empleado reg){
    cout << "ID: " << reg.getIdEmpleado() << endl;
    reg.mostrar();
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "DNI: " << reg.getDNI() << endl;
    cout << "ESTADO: " << (reg.getEstado() ? "Disponible" : "Eliminado") << endl;
}

void EmpleadoManager::modificar_empleado(){
   int id_empleado, index;
    Empleado empleado;
    cout << "Ingrese id del empleado a modificar: ";
    cin >> id_empleado;
    index = _empleados_archivo.buscarByID(id_empleado);
    if(index != -1){
        empleado = _empleados_archivo.leer(index);
        mostrar_empleados(empleado);
        modificar(empleado);
        if(_empleados_archivo.guardar(index, empleado)){
            cout << "Se modifico con exito!" << endl;
        }else{
            cout << "No se pudo modificar el empleado!" << endl;
        }
    }else{
        cout << "No se encuentra el empleado!" << endl;
    }
}


void EmpleadoManager::modificar(Empleado &registro){
    registro.modificar();
}

void EmpleadoManager::eliminar_empleado(){
    int id_empleado, index;
    Empleado empleado;
    bool eliminar;

    cout << "Ingrese id del empleado: ";
    cin >> id_empleado;
    index = _empleados_archivo.buscarByID(id_empleado);

    if(index != -1){
        empleado = _empleados_archivo.leer(index);
        mostrar_empleados(empleado);
        cout << "Esta seguro de que quiere eliminar este empleado? 1-Si 0-No: ";
        cin >> eliminar;
        if(eliminar){
            empleado.setEstado(false);
            if(_empleados_archivo.guardar(index, empleado)){
                cout << "Se elimino con exito el empleado!" << endl;            }
            else{
                cout << "No se pudo eliminar el empleado!" << endl;
            }
        }else{
            cout << "El empleado no fue eliminado!" << endl;
        }
    }else{
        cout << "No se encuentra el empleado!" << endl;
    }
}

void EmpleadoManager::listar_por_id(){
    int id_empleado, index;
    Empleado empleado;
    //bool eliminar;

    cout << "Ingrese id del empleado: ";
    cin >> id_empleado;
    index = _empleados_archivo.buscarByID(id_empleado);

    if(index != -1){
        empleado = _empleados_archivo.leer(index);
        mostrar_empleados(empleado);
    }
}
