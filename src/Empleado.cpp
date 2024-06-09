#include "iostream"
using namespace std;
#include "Empleado.h"
Empleado::Empleado(){
    _id_empleado=0;
    _sueldo=0.0;
    _ingreso=Fecha();
}

void Empleado::mostrar(){
    cout<<"SUELDO DE EMPLEADO: "<<_sueldo<<endl;
    Persona::mostrar();
}

void Empleado::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DEL EMPLEADO-------"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"INRESE EL SUELDO DEL EMPLEADO: ";
    cin>>_sueldo;
    Persona::cargar();
    cout<<"------------------------------"<<endl;
}

void Empleado::cargar(int id){
    _id_empleado=id;
    modificar();
}
