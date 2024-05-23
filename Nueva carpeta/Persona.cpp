#include "Persona.h"
#include "iostream"
#include <limits>

Persona::Persona(){
    _dni = 0;
    _estado = false;
}
void Persona::cargar() {
    std::cout << "DNI: ";
    std::cin >> _dni;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "FECHA NACIMIENTO: " << std::endl;
    _fechaNacimiento.cargar();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "NOMBRE: ";
    std::getline(std::cin, _nombre);
    std::cout << "APELLIDO: ";
    std::getline(std::cin, _apellido);
    std::cout << "EMAIL: ";
    std::getline(std::cin, _email);
    std::cout << "TELEFONO: ";
    std::getline(std::cin, _telefono);
    _estado = true;
}

void Persona::mostrar() {
    std::cout << "DNI: ";
    std::cout << _dni << std::endl;
    std::cout << "FECHA NACIMIENTO: " << std::endl;
    _fechaNacimiento.mostrar();
    std::cout << "NOMBRE: ";
    std::cout << _nombre << std::endl;
    std::cout << "APELLIDO: ";
    std::cout << _apellido << std::endl;
    std::cout << "EMAIL: ";
    std::cout << _email << std::endl;
    std::cout << "TELEFONO: ";
    std::cout << _telefono << std::endl;
}



