#pragma once
#include <string>
#include "Fecha.h"

class Autoparte
{
    private:
        int _id;
        char _nombre[100];
        float _precio;
        int _stock;
        int _stockMinimo;
        int _tipo;
        bool _eliminado;
        Fecha _fechaVencimiento;
        //int _idCategoria;

    public:
        Autoparte();
        Autoparte(int id, std::string nombre, float precio, int stock, int stockMinimo, int tipo, Fecha fechaVencimiento, bool eliminado);

        void setID(int id);
        void setNombre(std::string nombre);
        void setPrecio(float precio);
        void setStock(int stock);
        void setStockMinimo(int stockMinimo);
        void setTipo(int tipo);
        void setEliminado(bool eliminado);
        void setFechaVencimiento(Fecha fechaVencimiento);
        //void setIDCategoria(int idcategoria);

        int getID();
        std::string getNombre();
        float getPrecio();
        int getStock();
        int getStockMinimo();
        int getTipo();
        bool getEliminado();
        Fecha getFechaVencimiento();
        //int getIDCategoria();
};
