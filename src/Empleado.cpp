#include "iostream"
#include <cstring>
#include <limits>
using namespace std;
#include "Empleado.h"
Empleado::Empleado(){
    _id_empleado=0;
    _sueldo=0.0;
    _ingreso=Fecha();
}

void Empleado::mostrar(){
    cout << "ID: " << getIdEmpleado() << endl;
    cout<<"SUELDO DE EMPLEADO: "<<_sueldo<<endl;
    Persona::mostrar();
}

void Empleado::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DEL EMPLEADO-------"<<endl;
    cout<<"------------------------------"<<endl;
    cout << "INGRESE EL SUELDO DEL EMPLEADO: ";
        cin >> _sueldo;
        while (cin.fail() || _sueldo == 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "SUELDO NO VALIDO. POR FAVOR INTENTE DE NUEVO." << endl;
        cout << "INGRESE EL SUELDO DEL EMPLEADO: ";
        cin >> _sueldo;}
    Persona::cargar();
    cout<<"------------------------------"<<endl;
}

void Empleado::cargar(int id){
    _id_empleado=id;
    modificar();

}
