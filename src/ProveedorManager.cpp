#include <iostream>
using namespace std;
#include "ProveedorManager.h"

void ProveedorManager::menu(){
    int option;
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "---- MENU DE PROVEEDORES ----" << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR PROVEEDOR " << endl;
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
                agregar_proveedor();
                system("pause");
                break;
            case 2:
                listar_proveedor();
                system("pause");
                break;
            case 3:
                modificar_proveedor();
                system("pause");
                break;
            case 4:
                eliminar_proveedor();
                system("pause");
                break;
            case 5:
                listar_por_id();
                system("pause");
            break;
        }
    }while(option != 0);
}

Proveedor ProveedorManager::crear_proveedor(){
    Proveedor nuevo_proveedor;
    int id = _proveedores_archivo.getNuevoID();
    nuevo_proveedor.setIdProveedor(id);
    nuevo_proveedor.cargar(id);
    return nuevo_proveedor;
}

void ProveedorManager::agregar_proveedor(){
    if(_proveedores_archivo.guardar(crear_proveedor()))    {
        cout << "El proveedor fue guardado con exito!" << endl;
    }else{
        cout << "No se pudo guardar el proveedor!" << endl;
    }
}

void ProveedorManager::listar_proveedor(){
    int cantidad = _proveedores_archivo.getCantidadRegistros();
    Proveedor *proveedores;
    proveedores = new Proveedor[cantidad];
    if(proveedores == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _proveedores_archivo.leerTodos(proveedores, cantidad);
    for(int i=0; i<cantidad; i++){
        if(proveedores[i].getEstado()){
            cout << "--------------------------" << endl;
            mostrar_proveedor(proveedores[i]);
            cout << "--------------------------" << endl;
        }
    }
    delete [] proveedores;
}

void ProveedorManager::mostrar_proveedor(Proveedor reg){
    reg.mostrar();
    cout << "ESTADO: " << (reg.getEstado() ? "Disponible" : "Eliminado") << endl;
}

void ProveedorManager::modificar_proveedor(){
    int id_proveedor, index;
    Proveedor proveedor;
    cout << "Ingrese id del proveedor a modificar: ";
    cin >> id_proveedor;
    index = _proveedores_archivo.buscarByID(id_proveedor);
    if(index != -1){
        proveedor = _proveedores_archivo.leer(index);
        mostrar_proveedor(proveedor);
        modificar(proveedor);
        if(_proveedores_archivo.guardar(index, proveedor)){
            cout << "Se modifico con exito!" << endl;
        }else{
            cout << "No se pudo modificar el proveedor!" << endl;
        }
    }else{
        cout << "No se encuentra el proveedor!" << endl;
    }
}

void ProveedorManager::modificar(Proveedor &registro){
    registro.modificar();
}

void ProveedorManager::eliminar_proveedor(){
    int id_proveedor, index;
    Proveedor proveedor;
    bool eliminar;

    cout << "Ingrese id del Proveedor: ";
    cin >> id_proveedor;
    index = _proveedores_archivo.buscarByID(id_proveedor);

    if(index != -1){
        proveedor = _proveedores_archivo.leer(index);
        mostrar_proveedor(proveedor);
        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;
        if(eliminar){
            proveedor.setEstado(false);
            if(_proveedores_archivo.guardar(index, proveedor)){
                cout << "Se elimino con exito!" << endl;            }
            else{
                cout << "No se pudo eliminar el proveedor!" << endl;
            }
        }else{
            cout << "El proveedor no fue eliminado!" << endl;
        }
    }else{
        cout << "No se encuentra el proveedor!" << endl;
    }
}

void ProveedorManager::listar_por_id(){
    int id_proveedor, index;
    Proveedor proveedor;
    bool eliminar;

    cout << "Ingrese id del proveedor: ";
    cin >> id_proveedor;
    index = _proveedores_archivo.buscarByID(id_proveedor);

    if(index != -1){
        proveedor = _proveedores_archivo.leer(index);
        mostrar_proveedor(proveedor);
    }
}
