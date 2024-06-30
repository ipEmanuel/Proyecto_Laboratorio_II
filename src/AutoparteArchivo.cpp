#include "AutoparteArchivo.h"
#include "iostream"

AutoparteArchivo::AutoparteArchivo(): Archivo("autopartes", sizeof(Autoparte)) {
}

bool AutoparteArchivo::guardar(Autoparte reg){
   bool result = Archivo::guardar(&reg);
   return result;
}

bool AutoparteArchivo::guardar(int index, Autoparte reg){
   bool result = Archivo::guardar(&reg, 1, index);
   return result;
}

int AutoparteArchivo::buscarByID(int id){
    Autoparte reg;
    int pos = 0;
    while(Archivo::leer(pos, &reg)) {
    //while(fread(&reg, sizeof(Autoparte), 1, pFile)){
        if(reg.getIDAutoparte() == id){
            return pos;
        }
        pos++;
    }
    return -1;
}

Autoparte AutoparteArchivo::leer(int index){
   bool result;
   Autoparte reg;
   Archivo::leer(index, &reg);
   return reg;
}

bool AutoparteArchivo::leerTodos(Autoparte registros[], int cantidad){
   bool read = Archivo::leer(0, registros, cantidad);
   return read;
}

int AutoparteArchivo::getCantidadRegistros() {
    return Archivo::getCantidadRegistros();
}

int AutoparteArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();
    if(cantidad>0){
        return leer(cantidad-1).getIDAutoparte()+1;
    }
    else{
        return 1;
    }
}

bool AutoparteArchivo::crearBackup() {
    bool result;
    int cantidadReg = getCantidadRegistros();

    Autoparte* autopartes = new Autoparte[cantidadReg];

    bool canRead = leerTodos(autopartes, cantidadReg);

    if (!canRead) {
        return canRead;
    }

    return Archivo::crearBackup(cantidadReg, autopartes);
}

bool AutoparteArchivo::reestablecer() {
    bool result;
    setBackupMode(true);
    int cantidadReg = getCantidadRegistros();

    Autoparte* autopartes = new Autoparte[cantidadReg];

    bool canRead = leerTodos(autopartes, cantidadReg);

    if (!canRead) {
        cout << "NO SE PUDO LEER EL BACKUP" << endl;
        return canRead;
    }

    setBackupMode(false);

    Archivo::sobreescribirTodo(cantidadReg, autopartes);

    return result;
}
