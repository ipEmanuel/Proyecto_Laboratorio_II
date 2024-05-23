#include <cstring>
#include "Autoparte.h"

Autoparte::Autoparte(): _fechaVencimiento(1,1,1)
{
   _id = 0;
   strcpy(_nombre, "");
   _precio = 0.0f;
   _stock = 0;
   _stockMinimo = 0;
   _tipo = 0;
   _eliminado = 0;
}

Autoparte::Autoparte(int id, std::string nombre, float precio, int stock, int stockMinimo, int tipo, Fecha fechaVencimiento, bool eliminado)
: _fechaVencimiento(1,1,1)
{
   setID(id);
   setNombre(nombre);
   setPrecio(precio);
   setStock(stock);
   setStockMinimo(stockMinimo);
   setTipo(tipo);
   setEliminado(eliminado);
   setFechaVencimiento(fechaVencimiento);
  // setIDCategoria(idcategoria);
}

int Autoparte::getID(){
   return _id;
}

void Autoparte::setID(int id){
   _id = id;
}

std::string Autoparte::getNombre(){
   return _nombre;
}

void Autoparte::setNombre(std::string nombre){
   if(nombre.size() <= 100){
      strcpy(_nombre, nombre.c_str());
   }
   else{
      strcpy(_nombre, "SIN DATOS");
   }
}

float Autoparte::getPrecio(){
   return _precio;
}
void Autoparte::setPrecio(float precio){
   _precio = precio;
}

int Autoparte::getStock(){
   return _stock;
}
void Autoparte::setStock(int stock){
   _stock = stock;
}

int Autoparte::getStockMinimo(){
   return _stockMinimo;
}

void Autoparte::setStockMinimo(int stockMinimo){
   _stockMinimo = stockMinimo;
}

int Autoparte::getTipo(){
   return _tipo;
}

void Autoparte::setTipo(int tipo){
   _tipo = tipo;
}

bool Autoparte::getEliminado(){
   return _eliminado;
}

void Autoparte::setEliminado(bool eliminado){
   _eliminado = eliminado;
}

Fecha Autoparte::getFechaVencimiento(){
   return _fechaVencimiento;
}

void Autoparte::setFechaVencimiento(Fecha fechaVencimiento){
   _fechaVencimiento = fechaVencimiento;
}

/*
void Autoparte::setIDCategoria(int idcategoria){
   _idCategoria = idcategoria;
}

int Autoparte::getIDCategoria(){
   return _idCategoria;
}
*/
