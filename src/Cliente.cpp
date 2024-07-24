#include <limits>
#include "iostream"
using namespace std;
#include "Cliente.h"
#include "ClienteArchivo.h"

Cliente::Cliente(){
    _id_cliente = -1;
    _descuento = 0.0f;
    _categoria =0;
}

void Cliente::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DEL CLIENTE-------"<<endl;
    cout<<"------------------------------"<<endl;
    Persona::cargar();
     while(verificarDNIunico(_dni))
    {
        cout<<"DNI YA REGISTRADO, POR FAVOR CARGUE LOS DATOS DE NUEVO"<<endl;
        Persona::cargar();
    }}

bool Cliente::verificarDNIunico(int dni)
{
    ClienteArchivo archivo;
    Cliente reg;
    int tam=archivo.getCantidadRegistros();
    for(int i=0; i<tam; i++)
    {
        reg=archivo.leer(i);
        int dni2=reg.getDNI();
        if(dni2==dni )
        {
            return true;
        }

    }
    return false;
}



void Cliente::cargar(int id){
    _id_cliente=id;
    modificar();
}

void Cliente::mostrar(){
    if(_estado==true){
        cout<<"ID CLIENTE "<<_id_cliente<<endl;
        cout<<"DESCUENTO: "<<_descuento<<endl;
        cout<<"CATEGORIA "<<_categoria<<endl;
        cout<<"------------------------------"<<endl;
        Persona::mostrar();
    }
}
