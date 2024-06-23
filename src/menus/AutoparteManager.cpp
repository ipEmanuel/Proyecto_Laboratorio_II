#include <iostream>
#include "AutoparteManager.h"
using namespace std;

AutoparteManager::AutoparteManager(): MenuItem("Autopartes") {}

string AutoparteManager::obtenerNombreMarca(int cod_marca) {
    int index = _marcaArchivo.buscarByID(cod_marca);
    if (index != -1) {
        Marca marca = _marcaArchivo.leer(index);
        return string(marca.getNombre());
    }

    return string("Marca desconocida");
}

string AutoparteManager::obtenerNombreProveedor(int id_proveedor) {
    int index = _proveedorArchivo.buscarByID(id_proveedor);
    if (index != -1) {
        Proveedor proveedor = _proveedorArchivo.leer(index);
        return string(proveedor.getNombre());
    }
    return string("Proveedor desconocido");
}

Autoparte AutoparteManager::crearAutoparte(){
    int id_autoparte, id_proveedor, stock, cod_marca;
    char nombre_autoparte[60], opcion;
    float precio_compra, precio_venta;

    id_autoparte = _autopartesArchivo.getNuevoID();
    cin.ignore();


    while (true) {
        cout << "Ingrese codigo(id) del proveedor (o 'S' para salir): ";
        cin >> id_proveedor;

        if (cin.fail()) {  // si la entrada no es un número
            cin.clear();
            cin >> opcion;
            if (opcion == 'S' || opcion == 's') {
                cout << "Salida sin crear la autoparte." << endl;
                return Autoparte(); // Retornar un objeto vacío para indicar que no se creó la autoparte
            } else {
                cout << "Entrada no válida. Intente nuevamente." << endl;
                cin.ignore();
                continue;
            }
        }

        if (_proveedorArchivo.buscarByID(id_proveedor) != -1) {
            break; // Salir del bucle si se encontró un proveedor válido
        } else {
            cout << "ERROR: Proveedor No Valido. Intente nuevamente." << endl;
        }
    }

    cin.ignore();
    cout << "Ingrese el Nombre de la Autoparte: ";
    cin.getline(nombre_autoparte, sizeof(nombre_autoparte));

    while (true) {
        cout << "Ingrese precio de compra: ";
        cin >> precio_compra;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(); // Descartar la entrada inválida
            cout << "Entrada no valida. Por favor, ingrese un numero." << endl;
        } else {
            break; // Entrada válida, salir del bucle
        }
    }

    while (true) {
        cout << "Ingrese precio de venta: ";
        cin >> precio_venta;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(); // Descartar la entrada inválida
            cout << "Entrada no valida. Por favor, ingrese un numero." << endl;
        } else {
            break; // Entrada válida, salir del bucle
        }
    }

    while (true) {
        cout << "Ingrese stock: ";
        cin >> stock;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(); // Descartar la entrada inválida
            cout << "Entrada no valida. Por favor, ingrese un numero." << endl;
        } else {
            break; // Entrada válida, salir del bucle
        }
    }
    cout << "Ingrese Codigo de Marca: ";
    cin >> cod_marca;

    // Bucle para obtener un código de marca válido
    while (_marcaArchivo.buscarByID(cod_marca) == -1) {
        cout << "ERROR: Marca No Valida. Intente nuevamente." << endl;
        cout << "Ingrese Codigo de Marca: ";
        cin >> cod_marca;
    }

    return Autoparte(id_autoparte, id_proveedor, nombre_autoparte, precio_compra, precio_venta, stock, cod_marca, true);
}

void AutoparteManager::volverCargarAutoparte(Autoparte &registro){
    int id_proveedor = -1;
    int stock, cod_marca;
    string nombre_autoparte;
    char opcion;
    float precio_compra, precio_venta;

    cin.ignore();

    while (id_proveedor == -1 || _proveedorArchivo.buscarByID(id_proveedor) == -1) {
        cout << "Ingrese codigo(id) del proveedor (o 'S' para salir): ";
        cin >> id_proveedor;

        if (cin.fail()) {  // verificar si la entrada no es un número
            cin.clear();
            cin >> opcion;
            if (opcion == 'S' || opcion == 's') {
                cout << "Salida sin crear la autoparte." << endl;
                return;
            } else {
                cout << "Entrada no válida. Intente nuevamente." << endl;
                cin.ignore();
                continue;
            }
        }

        cout << "ERROR: Proveedor No Valido. Intente nuevamente." << endl;
    }

    cin.ignore();
    cout << "Ingrese el Nombre de la Autoparte: ";
    getline(cin, nombre_autoparte);
    cout << "Ingrese precio de compra: ";
    cin >> precio_compra;
    cout << "Ingrese precio de venta: ";
    cin >> precio_venta;
    cout << "Ingrese stock: ";
    cin >> stock;
    cout << "Ingrese Codigo de Marca: ";
    cin >> cod_marca;

    // Bucle para obtener un código de marca válido
    while (_marcaArchivo.buscarByID(cod_marca) == -1) {
        cout << "ERROR: Marca No Valida. Intente nuevamente." << endl;
        cout << "Ingrese Codigo de Marca: ";
        cin >> cod_marca;
    }

    registro.setIDProveedor(id_proveedor);
    registro.setNombre(nombre_autoparte);
    registro.setPrecioCompra(precio_compra);
    registro.setPrecioVenta(precio_venta);
    registro.setStock(stock);
    registro.setCodMarca(cod_marca);

}

void AutoparteManager::ordenarAutopartesPorPrecioVenta(Autoparte autoparte[], int cantidad){
   int i, j;
   int posMaximo;
   for(i = 0; i < cantidad - 1; i++){
      posMaximo = i;
      for (j = i + 1; j < cantidad; j++){
         if (autoparte[j].getPrecioVenta() > autoparte[posMaximo].getPrecioVenta()){
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
      ordenarAutopartesPorPrecioVenta(autopartes, cantidad);
    }
    for(int i=0; i<cantidad; i++){
        if(autopartes[i].getEstado()){
            cout << "--------------------------" << endl;
            autopartes[i].mostrar();
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
        autoparte.mostrar();
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
        autoparte.mostrar();
        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;
        if(eliminar){
            autoparte.setEstado(false);
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

int AutoparteManager::execute(){
    int option;
    do{
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "------- MENU AUTOPARTES --------" << endl;
        cout << "--------------------------------" << endl;
        cout << "1- AGREGAR AUTOPARTE            " << endl;
        cout << "2- LISTAR TODAS LAS AUTOPARTES  " << endl;
        cout << "3- MODIFICAR AUTOPARTE          " << endl;
        cout << "4- ELIMINAR AUTOPARTE           " << endl;
        cout << "5- LISTAR ORDENADOS POR PRECIO  " << endl;
        cout << "________________________________" << endl;
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
    } while(option != 0);
    system("cls");
    return 0;
}
