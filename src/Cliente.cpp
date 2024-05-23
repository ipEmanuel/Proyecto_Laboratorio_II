#include "Cliente.h"
#include "iostream"
#include <limits>

Cliente::Cliente(){
    _id_cliente = -1;
    _descuento = 0.0f;
    _categoria =0;
}

void Cliente::modificar(){
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"------DATOS DEL CLIENTE-------"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    Persona::cargar();
    std::cout<<"------------------------------"<<std::endl;
    std::cout<<"INGRESAR DESCUENTO: ";
    std::cin>>_descuento;
    while (std::cin.fail() || _descuento < 0.0f) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "DESCUENTO INVALIDO. INGRESE NUEVAMENTE: ";
        std::cin >> _descuento;
    }

    std::cout<<"INGRESAR CATEGORIA: ";
    std::cin>>_categoria;
    while (std::cin.fail() || _categoria < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "CATEGORIA INVALIDA. INGRESE NUEVAMENTE: ";
        std::cin >> _categoria;
    }


}

void Cliente::cargar(int id){
    _id_cliente=id;
    modificar();
}

void Cliente::mostrar(){
    if(_estado==true){
        std::cout<<"ID CLIENTE "<<_id_cliente<<std::endl;
        std::cout<<"DESCUENTO: "<<_descuento<<std::endl;
        std::cout<<"CATEGORIA "<<_categoria<<std::endl;
        std::cout<<"------------------------------"<<std::endl;
        Persona::mostrar();
    }
}
