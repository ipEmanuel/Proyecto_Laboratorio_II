#include "cstring"
#include <iostream>
using namespace std;
#include "MenuItem.h"
#include "MarcaManager.h"
#include "Marca.h"

MarcaManager::MarcaManager(): MenuItem("Marcas", 2) {}

int MarcaManager::execute(){
int option;
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "----- MENU DE MARCAS ------ " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR MARCA " << endl;
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
                agregar_marca();
                system("pause");
                break;
            case 2:
                listar_marcas();
                system("pause");
                break;
            case 3:
                modificar_marca();
                system("pause");
                break;
            case 4:
                eliminar_marca();
                system("pause");
                break;
            case 5:
                listar_por_id();
                system("pause");
            break;

        }
    }
    while(option != 0);
}

Marca MarcaManager::crear_marca(){
    Marca nueva_marca;
    int id = _marcas_archivo.getNuevoID();
    nueva_marca.setIdMarca(id);
    nueva_marca.cargar(id);
    return nueva_marca;
}

void MarcaManager::agregar_marca(){
    if(_marcas_archivo.guardar(crear_marca()))    {
        cout << "La marca fue guardada con exito!" << endl;
    }else{
        cout << "No se pudo guardar la marca!" << endl;
    }
}

void MarcaManager::listar_marcas(){
    int cantidad = _marcas_archivo.getCantidadRegistros();
    Marca *marcas;
    marcas = new Marca[cantidad];
    if(marcas == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _marcas_archivo.leerTodos(marcas, cantidad);
    for(int i=0; i<cantidad; i++){
        if(marcas[i].getEstado()){
            cout << "--------------------------" << endl;
            mostrar_marcas(marcas[i]);
            cout << "--------------------------" << endl;
        }
    }
    delete [] marcas;
}

void MarcaManager::mostrar_marcas(Marca reg){
    reg.mostrar();
    cout << "ESTADO: " << (reg.getEstado() ? "Disponible" : "Eliminado") << endl;
}

void MarcaManager::modificar_marca(){
   int id_marca, index;
    Marca marca;
    cout << "Ingrese id de la marca a modificar: ";
    cin >> id_marca;
    index = _marcas_archivo.buscarByID(id_marca);
    if(index != -1){
        marca = _marcas_archivo.leer(index);
        mostrar_marcas(marca);
        modificar(marca);
        if(_marcas_archivo.guardar(index, marca)){
            cout << "Se modifico con exito!" << endl;
        }else{
            cout << "No se pudo modificar la marca!" << endl;
        }
    }else{
        cout << "No se encuentra la marca!" << endl;
    }
}

void MarcaManager::modificar(Marca &registro){
    registro.modificar();
}

void MarcaManager::eliminar_marca(){
    int id_marca, index;
    Marca marca;
    bool eliminar;

    cout << "Ingrese id de la marca: ";
    cin >> id_marca;
    index = _marcas_archivo.buscarByID(id_marca);

    if(index != -1){
        marca = _marcas_archivo.leer(index);
        mostrar_marcas(marca);
        cout << "Esta seguro de que quiere eliminar esta marca? 1-Si 0-No: ";
        cin >> eliminar;
        if(eliminar){
            marca.setEstado(false);
            if(_marcas_archivo.guardar(index, marca)){
                cout << "Se elimino con exito la marca!" << endl;            }
            else{
                cout << "No se pudo eliminar la marca!" << endl;
            }
        }else{
            cout << "La marca no fue eliminado!" << endl;
        }
    }else{
        cout << "No se encuentra la marca!" << endl;
    }
}

void MarcaManager::listar_por_id(){
    int id_marca, index;
    Marca marca;
    bool eliminar;

    cout << "Ingrese id de la marca: ";
    cin >> id_marca;
    index = _marcas_archivo.buscarByID(id_marca);

    if(index != -1){
        marca = _marcas_archivo.leer(index);
        mostrar_marcas(marca);
    }
}





