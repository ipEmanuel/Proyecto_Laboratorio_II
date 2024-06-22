#pragma once
#include "Fecha.h"
#include "cstring"

class Persona {
    protected:
        int _dni;
        char _apellido[60];
        char _nombre[60];
        Fecha _fechaNacimiento;
        char _domicilio[60];
        char _telefono[60];
        char _email[60];
        bool _estado;

    public:
        Persona();
        ///GETTERS
        int getDNI() const { return _dni; }
        //Fecha getFechaNacimiento() const { return _fechaNacimiento; }
        const char* getNombre(){return _nombre;}
        //const char* getApellido(){return _apellido;}
        //const char* getEmail(){return _email;}
        //const char* getTelefono(){return _telefono;}
        //const char* getDomicilio(){ return _domicilio; }
        bool getEstado() const { return _estado; }

        ///SETTERS
        //void setDNI(int dni) { _dni = dni; }
        //void setFechaNacimiento(const Fecha &fn){_fechaNacimiento = fn;}
        //void setNombre(const char *n){strcpy(_nombre,n);}
        //void setApellido(const char *a){strcpy(_apellido, a);}
        //void setEmail(const char *e){strcpy(_email,e);}
        //void setTelefono(const char *t){strcpy(_telefono,t);}
        //void setDomicilio(const char *d){strcpy(_domicilio, d);}
        void setEstado(bool estado) {_estado = estado;}

        ///METODOS
        void cargar();
        void mostrar();
};
