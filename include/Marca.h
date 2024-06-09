#pragma once
#include "cstring"
class Marca{
    private:
        int _IDmarca;
        char _Nombre[30];
        bool _Estado;

    public:

        //setters
        Marca();
        void setIdMarca(int ID){_IDmarca=ID;};
        void setMarca(const char *n){strcpy(_Nombre, n);};
        void setEstado(bool e){_Estado=e;};

        //getters

        int getIdMarca(){return _IDmarca;};
        const char* getNombre(){return _Nombre;};
        bool getEstado(){return _Estado;};

        void cargar(int ID);
        void mostrar();
        void modificar();
};
