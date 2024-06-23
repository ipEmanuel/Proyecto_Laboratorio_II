#include "cstring"
#include <iostream>
using namespace std;
#include "Marca.h"


Marca::Marca(){
    _IDmarca = 0;
    _Estado=false;
}

void Marca::cargar(int ID){
    _IDmarca=ID;
    cin.ignore();
    modificar();
}
void Marca::mostrar(){
    cout<<"ID MARCA: "<<_IDmarca<<endl;
    cout<<"NOMBRE MARCA: "<<_Nombre<<endl;
}

void Marca::modificar(){
    cout<<"------------------------------"<<endl;
    cout<<"------DATOS DE LA MARCA-------"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"------------------------------"<<endl;

    cout<<"NOMBRE: ";
    cin.getline(_Nombre, 30);
    _Estado = true;
}
