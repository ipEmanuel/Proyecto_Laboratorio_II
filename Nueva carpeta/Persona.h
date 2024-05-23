#pragma once
#include "Fecha.h"
#include <cstring>

class Persona {
    protected:
        int _dni;
        std::string _apellido;
        std::string _nombre;
        Fecha _fechaNacimiento;
        std::string _domicilio;
        std::string _telefono;
        std::string _email;
        bool _estado;

    public:
        Persona();
        ///GETTERS
        int getDNI() const { return _dni; }
        std::string getApellido() const { return _apellido; }
        std::string getNombre() const { return _nombre; }
        Fecha getFechaNacimiento() const { return _fechaNacimiento; }
        std::string getDomicilio() const { return _domicilio; }
        std::string getTelefono() const { return _telefono; }
        std::string getMail() const { return _email; }
        bool getEstado() const { return _estado; }

        ///SETTERS
        void setDNI(int dni) { _dni = dni; }
        void setApellido(const std::string &a) { _apellido = a; }
        void setNombre(const std::string &n) { _nombre = n; }
        void setFechaNacimiento(const Fecha &fn) { _fechaNacimiento = fn; }
        void setDomicilio(const std::string &d) { _domicilio = d; }
        void setTelefono(const std::string &t) { _telefono = t; }
        void setMail(const std::string &e) { _email = e; }
        void setEstado(bool estado) { _estado = estado; }

        ///METODOS
        void cargar();
        void mostrar();
};
