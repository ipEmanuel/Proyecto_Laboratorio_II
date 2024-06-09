#pragma once
#include "Persona.h"
#include "Fecha.h"
class Empleado : public Persona{
    private:
		int _id_empleado;
		float _sueldo;
        Fecha _ingreso;

    public:
        Empleado();

        //Setters
        void setIdEmpleado(int id){_id_empleado=id;};
        void setSueldo(float sueldo){_sueldo=sueldo;};
        void setIngreso(Fecha ingreso){_ingreso=ingreso;};

        //Getters
        int getIdEmpleado(){return _id_empleado;} ;
        float getSueldo() {return _sueldo;};
        void getIngreso() {
            _ingreso.mostrar();
        };

        void cargar(int id);
        void mostrar();
        void modificar();
};
