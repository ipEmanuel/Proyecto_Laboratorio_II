#include <iostream>
using namespace std;
#include "AutoparteManager.h"

Autoparte AutoparteManager::crearAutoparte(){
    int id, stock, stockMinimo, tipo;
    string nombre;
    float precio;
    Fecha fv;

    id = _autopartesArchivo.getNuevoID();
    cout << "Ingrese ID: " << id<< endl;
    cin.ignore();
    cout <<"Ingrese nombre: ";
    getline(cin, nombre);
    cout<< "Ingrese precio: ";
    cin >> precio;
    cout<< "Ingrese stock: ";
    cin >> stock;
    cout<< "Ingrese stock minimo: ";
    cin>> stockMinimo;
    cout << "Ingrese tipo: ";
    cin >> tipo;
    cout << "Ingrese Fecha de Vencimiento: "<<endl;
    fv.cargar();
    return Autoparte(id, nombre, precio, stock, stockMinimo, tipo, fv, false);
}

void AutoparteManager::volverCargarAutoparte(Autoparte &registro){
    int id, stock, stockMinimo, tipo;
    string nombre;
    float precio;
    Fecha fv;

    cin.ignore();
    cout <<"Ingrese nombre: ";
    getline(cin, nombre);
    cout<< "Ingrese precio: ";
    cin >> precio;
    cout<< "Ingrese stock: ";
    cin >> stock;
    cout<< "Ingrese stock minimo";
    cin>> stockMinimo;
    cout << "Ingrese tipo: ";
    cin >> tipo;
    cout << "Ingrese Fecha de Vencimiento";
    fv.cargar();
    registro.setNombre(nombre);
    registro.setPrecio(precio);
    registro.setStock(stock);
    registro.setStockMinimo(stockMinimo);
    registro.setTipo(tipo);
    registro.setFechaVencimiento(fv);
}

void AutoparteManager::mostrarAutoparte(Autoparte reg){
    cout << "ID: " << reg.getID() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Precio: " << reg.getPrecio() << endl;
    cout << "Stock: " << reg.getStock() << endl;
    cout << "Stock Minimo: " << reg.getStockMinimo() << endl;
    cout << "Fecha vencimiento: " << reg.getFechaVencimiento().toString() << endl;
    cout << "Estado: " << (reg.getEliminado() ? "Eliminado": "Disponible") << endl;
}

void AutoparteManager::ordenarAutopartesPorPrecio(Autoparte autoparte[], int cantidad){
   int i, j;
   int posMaximo;
   for(i = 0; i < cantidad - 1; i++){
      posMaximo = i;
      for (j = i + 1; j < cantidad; j++){
         if (autoparte[j].getPrecio() > autoparte[posMaximo].getPrecio()){
            posMaximo = j;
         }
      }
      if (i != posMaximo){
         Autoparte aux = autoparte[i];
         autoparte[i] = autoparte[posMaximo];
         autoparte[posMaximo] = aux;
      }
   }
}

////DEL MENU////
void AutoparteManager::agregarAutoparte(){
    if(_autopartesArchivo.guardar(crearAutoparte())){
        cout << "La autoparte fue guardado con exito!" << endl;
    }else{
        cout << "No se pudo guardar la autoparte!" << endl;
    }
}

void AutoparteManager::listarAutoparte(bool ordenadoPorPrecio){
    int cantidad = _autopartesArchivo.getCantidadRegistros();
    Autoparte *autopartes;
    autopartes = new Autoparte[cantidad];

    if(autopartes == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _autopartesArchivo.leerTodos(autopartes, cantidad);
    if (ordenadoPorPrecio){
      ordenarAutopartesPorPrecio(autopartes, cantidad);
    }
    for(int i=0; i<cantidad; i++){
        if(!autopartes[i].getEliminado()){
            cout << "--------------------------" << endl;
            mostrarAutoparte(autopartes[i]);
            cout << "--------------------------" << endl;
        }
    }
    delete [] autopartes;
}

void AutoparteManager::modificarAutoparte(){
    int idAutoparte, index;
    Autoparte autoparte;

    cout << "Ingrese id del autoparte a modificar: ";
    cin >> idAutoparte;

    index = _autopartesArchivo.buscarByID(idAutoparte);
    if(index != -1){
        autoparte = _autopartesArchivo.leer(index);
        mostrarAutoparte(autoparte);
        volverCargarAutoparte(autoparte);
        if(_autopartesArchivo.guardar(index, autoparte)){
            cout << "Se modifico con exito!" << endl;
        }else{
            cout << "No se pudo modificar la autoparte!" << endl;
        }
    }else{
        cout << "No se encuentra ese autoparte!" << endl;
    }
}

void AutoparteManager::eliminarAutoparte(){
    int idAutoparte, index;
    Autoparte autoparte;
    bool eliminar;

    cout << "Ingrese id de la autoparte a eliminar: ";
    cin >> idAutoparte;
    index = _autopartesArchivo.buscarByID(idAutoparte);

    if(index != -1){
        autoparte = _autopartesArchivo.leer(index);
        mostrarAutoparte(autoparte);
        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;
        if(eliminar){
            autoparte.setEliminado(true);
            if(_autopartesArchivo.guardar(index, autoparte)){
                cout << "Se elimino con exito!" << endl;
            }else{
                cout << "No se pudo eliminar la autoparte!" << endl;
            }
        }else{
            cout << "La autoparte no fue eliminada!" << endl;
        }
    }else{
        cout << "No se encuentra esa Autoparte!" << endl;
    }
}

void AutoparteManager::menu(){
    int option;
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "------ MENU AUTOPARTES ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR AUTOPARTE " << endl;
        cout << "2- LISTAR TODAS LAS AUTOPARTES" << endl;
        cout << "3- MODIFICAR AUTOPARTE" << endl;
        cout << "4- ELIMINAR AUTOPARTE" << endl;
        cout << "5- LISTAR ORDENADOS POR PRECIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option){
            case 1:
                agregarAutoparte();
                system("pause");
                break;

            case 2:
                listarAutoparte();
                system("pause");
                break;

            case 3:
                modificarAutoparte();
                system("pause");
                break;

            case 4:
                eliminarAutoparte();
                system("pause");
                break;

            case 5:
                listarAutoparte(true);
                system("pause");
             break;
        }
    }while(option != 0);
}
