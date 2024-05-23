#pragma once
#include "Autoparte.h"
#include "AutoparteArchivo.h"

class AutoparteManager {
public:
   void menu();
private:
   void agregarAutoparte();
   void listarAutoparte(bool ordenadoPorPrecio = false);
   Autoparte crearAutoparte();
   void volverCargarAutoparte(Autoparte &registro);
   void mostrarAutoparte(Autoparte registro);
   void modificarAutoparte();
   void eliminarAutoparte();
   void ordenarAutopartesPorPrecio(Autoparte *autopartes, int cantidad);

   AutoparteArchivo _autopartesArchivo;

};
