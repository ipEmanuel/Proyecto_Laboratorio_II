#include "iostream"
#include <cstring>
#include <limits>
using namespace std;
#include "Persona.h"


Persona::Persona(){
    _estado = false;
}
void Persona::cargar() {

        cout << "INGRESE DNI: ";
        cin >> _dni;
        while (cin.fail() || _dni == 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "DNI NO VALIDO. POR FAVOR INTENTE DE NUEVO." << endl;
        cout << "INGRESE DNI: ";
        cin >> _dni;


        }
        cin.ignore();
            cout << "INGRESE NOMBRE: ";
            cin.getline(_nombre, 60);
     while (strlen(_nombre) == 0) {
            cout << "NOMBRE NO PUEDE ESTAR VACIO. POR FAVOR INTENTE DE NUEVO."<<endl;;
            cout << "INGRESE NOMBRE: ";
            cin.getline(_nombre, 60);

        }

            cout << "INGRESE APELLIDO: ";
            cin.getline(_apellido, 60);
    while (strlen(_apellido) == 0) {
            cout << "APELLIDO NO PUEDE ESTAR VACIO. POR FAVOR INTENTE DE NUEVO."<<endl;
            cout << "INGRESE APELLIDO: ";
            cin.getline(_apellido, 60);
        }

            cout << "INGRESE EMAIL: ";
            cin.getline(_email, 60);
    while (strlen(_email) == 0) {
            cout << "EMAIL NO PUEDE ESTAR VACIO. POR FAVOR INTENTE DE NUEVO."<< endl;
            cout << "INGRESE EMAIL: ";
            cin.getline(_email, 60);

        }
            cout << "INGRESE TELEFONO: ";
            cin.getline(_telefono, 60);
     while (strlen(_telefono) == 0 ) {
            cout << "TELEFONO NO PUEDE ESTAR VACIO. POR FAVOR INTENTE DE NUEVO."<<endl;
            cout << "INGRESE TELEFONO: ";
            cin.getline(_telefono, 60);

        }

            cout << "INGRESE DOMICILIO: ";
            cin.getline(_domicilio, 60);
     while (strlen(_domicilio) == 0) {
            cout << "DOMICILIO NO PUEDE ESTAR VACIO. POR FAVOR INTENTE DE NUEVO."<< endl;;
            cout << "INGRESE DOMICILIO: ";
            cin.getline(_domicilio, 60);

        }
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
