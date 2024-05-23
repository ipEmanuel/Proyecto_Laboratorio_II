#pragma once
#include "Persona.h"

class Cliente : public Persona {
	private:
		int _id_cliente;
		float _descuento;
        int _categoria;

	public:
	    Cliente();

	    ///GETTERS
		int getIdCliente() const { return _id_cliente; }
        float getDescuento() const { return _descuento; }
        int getCategoria() const { return _categoria; }
        ///SETTERS
		void setIdCliente(int id) { _id_cliente = id; }
        void setDescuento(float d) { _descuento = d; }
        void setCategoria(int c) { _categoria = c; }
        ///METODOS
        void modificar();
        void cargar(int id);
        void mostrar();
};


