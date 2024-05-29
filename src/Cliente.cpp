#include <limits>
#include "iostream"
using namespace std;
#include "Cliente.h"

Cliente::Cliente(){
    _id_cliente = -1;
    _descuento = 0.0f;
    _categoria =0;
}

void Cliente::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DEL CLIENTE-------"<<endl;
    cout<<"------------------------------"<<endl;
    Persona::cargar();
    cout<<"------------------------------"<<endl;
    cout<<"INGRESAR DESCUENTO: ";
    cin>>_descuento;
    while (cin.fail() || _descuento < 0.0f) {
        cin.clear();
        cin.ignore(numeric_limits< streamsize>::max(), '\n');
        cout << "DESCUENTO INVALIDO. INGRESE NUEVAMENTE: ";
        cin >> _descuento;
    }

    cout<<"INGRESAR CATEGORIA: ";
    cin>>_categoria;
    while (cin.fail() || _categoria < 0) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize>::max(), '\n');
        cout << "CATEGORIA INVALIDA. INGRESE NUEVAMENTE: ";
        cin >> _categoria;
    }


}

void Cliente::cargar(int id){
    _id_cliente=id;
    modificar();
}

void Cliente::mostrar(){
    if(_estado==true){
        cout<<"ID CLIENTE "<<_id_cliente<<endl;
        cout<<"DESCUENTO: "<<_descuento<<endl;
        cout<<"CATEGORIA "<<_categoria<<endl;
        cout<<"------------------------------"<<endl;
        Persona::mostrar();
    }
}
