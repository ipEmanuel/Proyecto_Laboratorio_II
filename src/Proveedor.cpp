#include "iostream"
using namespace std;
#include "Proveedor.h"

Proveedor::Proveedor(){
    _id_proveedor = -1;
    _estado = false;
}
void Proveedor::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"-----DATOS DEL PROVEEDOR------"<<endl;
    cout<<"------------------------------"<<endl;
    cin.ignore();
    cout << "NOMBRE: ";
    cin.getline(_nombre, 60);
    cout << "EMAIL: ";
    cin.getline(_email, 60);
    cout << "TELEFONO: ";

    cin.getline(_telefono, 60);
    cout << "DOMICILIO: ";
    cin.getline(_domicilio, 60);
    _estado = true;
}
void Proveedor::cargar(int id) {
    _id_proveedor = id;
    modificar();
}

void Proveedor::mostrar() {
    cout << "ID: ";
    cout << _id_proveedor << endl;
    cout << "NOMBRE: ";
    cout << _nombre << endl;
    cout << "EMAIL: ";
    cout << _email << endl;
    cout << "TELEFONO: ";
    cout << _telefono << endl;
    cout << "DOMICILIO: ";
    cout << _domicilio <<endl;
}
