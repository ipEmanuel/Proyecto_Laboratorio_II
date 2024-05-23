#include <iostream>
using namespace std;
#include "ClienteManager.h"

void ClienteManager::menu(){
    int option;
    do
    {
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "------ MENU AUTOPARTES ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AGREGAR CLIENTE " << endl;
        cout << "2- LISTAR" << endl;
        cout << "3- MODIFICAR " << endl;
        cout << "4- ELIMINAR" << endl;
        cout << "5- LISTAR POR ID" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            agregar_cliente();
            system("pause");
            break;

        case 2:
            listar_clientes();
            system("pause");
            break;

        case 3:
            modificar_cliente();
            system("pause");
            break;

        case 4:
            cout << "eliminarAutoparte();"<< endl;
            system("pause");
            break;

        case 5:
            cout << "listarAutoparte(true);"<< endl;
            system("pause");
         break;
        }

    }
    while(option != 0);
}

Cliente ClienteManager::crear_cliente(){
    Cliente nuevo_cliente;
    int id = _clientes_archivo.getNuevoID();
    nuevo_cliente.setIdCliente(id);
    nuevo_cliente.cargar(id);
    return nuevo_cliente;
}

void ClienteManager::agregar_cliente(){
    if(_clientes_archivo.guardar(crear_cliente()))    {
        cout << "El cliente fue guardado con exito!" << endl;
    }else{
        cout << "No se pudo guardar el cliente!" << endl;
    }
}

void ClienteManager::listar_clientes(){
    int cantidad = _clientes_archivo.getCantidadRegistros();
    Cliente *clientes;
    clientes = new Cliente[cantidad];
    if(clientes == nullptr){
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _clientes_archivo.leerTodos(clientes, cantidad);
    for(int i=0; i<cantidad; i++){
        if(clientes[i].getEstado()){
            cout << "--------------------------" << endl;
            mostrar_clientes(clientes[i]);
            cout << "--------------------------" << endl;
        }
    }
    delete [] clientes;
}

void ClienteManager::mostrar_clientes(Cliente reg)
{
    cout << "ID: " << reg.getIdCliente() << endl;
    cout << "Nombre: " << reg.getNombre() << endl;
    cout << "Descuento: " << reg.getDescuento() << endl;
    cout << "Categoria: " << reg.getCategoria() << endl;
    cout << "DNI: " << reg.getDNI() << endl;
    cout << "Estado: " << (reg.getEstado() ? "Disponible" : "Eliminado") << endl;
}

void ClienteManager::modificar_cliente(){
    int id_cliente, index;
    Cliente cliente;
    cout << "Ingrese id del producto a modificar: ";
    cin >> id_cliente;
    index = _clientes_archivo.buscarByID(id_cliente);
    if(index != -1){
        cliente = _clientes_archivo.leer(index);
        mostrar_clientes(cliente);
        modificar(cliente);
        if(_clientes_archivo.guardar(index, cliente)){
            cout << "Se modifico con exito!" << endl;
        }else{
            cout << "No se pudo modificar el cliente!" << endl;
        }
    }else{
        cout << "No se encuentra el cliente!" << endl;
    }
}

void ClienteManager::modificar(Cliente &registro){
    registro.modificar();
}
