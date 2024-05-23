#include "iostream"
using namespace std;
#include "Persona.h"

Persona::Persona(){
    _dni = 0;
    _estado = false;
}
void Persona::cargar() {
    cout << "DNI: ";
    cin >> _dni;
    cout<<"NOMBRE: ";
    cin>>_nombre;
    cout<<"APELLIDO: ";
    cin>>_apellido;
    cout<<"EMAIL: ";
    cin>>_email;
    cout<<"TELEFONO: ";
    cin>>_telefono;
    cout<<"DOMICILIO: ";
    cin>>_domicilio;
    cout << "FECHA NACIMIENTO: " <<endl;
    _fechaNacimiento.cargar();
    _estado = true;
}

void Persona::mostrar() {
    cout << "DNI: ";
    cout << _dni << endl;
    cout << "FECHA NACIMIENTO: " << endl;
    _fechaNacimiento.mostrar();
    cout << "NOMBRE: ";
    cout << _nombre << endl;
    cout << "APELLIDO: ";
    cout << _apellido << endl;
    cout << "EMAIL: ";
    cout << _email << endl;
    cout << "TELEFONO: ";
    cout << _telefono << endl;
    cout << "DOMICILIO: ";
    cout << _domicilio <<endl;
}



