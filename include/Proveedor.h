#pragma once
#include <cstring>

class Proveedor{
    private:
        int _id_proveedor;
        char _nombre[60];
        char _domicilio[60];
        char _telefono[60];
        char _email[60];
        bool _estado;
    public:
        Proveedor();
        //GETTERS
        int getIdProveedor() const{ return _id_proveedor; }
        const char* getNombre(){ return _nombre; }
        const char* getEmail(){ return _email; }
        const char* getTelefono(){ return _telefono; }
        const char* getDomicilio(){ return _domicilio; }
        bool getEstado() const{ return _estado; }

        //SETTERS
        void setIdProveedor(int id){ _id_proveedor = id; }
        void setNombre( const char *n ){strcpy( _nombre,n ); }
        void setEmail( const char *e ){ strcpy(_email,e); }
        void setTelefono( const char *t ){ strcpy( _telefono,t ); }
        void setDomicilio( const char *d ){ strcpy( _domicilio, d ); }
        void setEstado( bool estado ){ _estado = estado; }

        ///METODOS
        void modificar();
        void cargar(int id);
        void mostrar();
};
