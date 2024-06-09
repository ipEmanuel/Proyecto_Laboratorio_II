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
    cin.ignore();  // Ignorar el carácter de nueva línea residual

    cout << "NOMBRE: ";
    cin.getline(_nombre, 60);

    cout << "APELLIDO: ";
    cin.getline(_apellido, 60);

    cout << "EMAIL: ";
    cin.getline(_email, 60);

    cout << "TELEFONO: ";
    cin.getline(_telefono, 60);

    cout << "DOMICILIO: ";
    cin.getline(_domicilio, 60);

    cout << "FECHA NACIMIENTO: " << endl;
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



