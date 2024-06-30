#include "Archivo.h"
#include "iostream"
#include "cstring"

Archivo::Archivo(string nombre_archivo, size_t classSize, bool backup_mode)
{
    _archivo_nombre = nombre_archivo;
    _class_size = classSize;
    _backup_mode = backup_mode;
}

Archivo::~Archivo()
{
    //dtor
}

void Archivo::setBackupMode(bool active) {
    _backup_mode = active;
}

const char* Archivo::obtenerNombreArchivo() {
    string s;
    if (_backup_mode) {
        s = (_archivo_nombre + ".bkp");
    } else {
        s = (_archivo_nombre + ".dat");
    }
    const char * res = s.c_str();
    strcpy(aux, res);
    return aux;
}

bool Archivo::crearBackup(int cantidadReg, const void* data) {
    setBackupMode(true);
    FILE *pFile = fopen(obtenerNombreArchivo(), "wb");
    if(pFile == nullptr){
        std::cout << "Error al crear el archivo " << _archivo_nombre << endl;
        return false;
    }
    int writeSize = fwrite(data, _class_size, cantidadReg, pFile);
    fclose(pFile);
    setBackupMode(false);
    return writeSize > 0;
}

bool Archivo::sobreescribirTodo(int cantReg, const void* data) {
    FILE *pFile;
    const char* n = obtenerNombreArchivo();
    pFile = fopen(n, "wb");
    if(pFile == nullptr){
      return false;
    }
    int write = fwrite(data, _class_size, cantReg, pFile);
    fclose(pFile);
    return write > 0;
}

int Archivo::getCantidadRegistros(){
   FILE *pFile = fopen(obtenerNombreArchivo(), "rb");
   if(pFile == nullptr){
        cout << "ERROR ABRIENDO: " << obtenerNombreArchivo() << endl;
        return 0;
   }
   fseek(pFile, 0, SEEK_END);
   int tam = ftell(pFile) / _class_size;
   fclose(pFile);
   return tam;
}

bool Archivo::leer(int index, void* puntero, int cantidad){
   bool result;
   FILE *pFile;
   pFile = fopen(obtenerNombreArchivo(), "rb");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, index * _class_size, SEEK_SET);
   int read = fread(puntero, _class_size, cantidad, pFile);
   fclose(pFile);
   return read > 0;
}

bool Archivo::guardar(const void* reg, int cantidad, int index){
    bool result;
    FILE *pFile;
    pFile = fopen(obtenerNombreArchivo(), "rb+");
    if(pFile == nullptr){
      return false;
    }
    if (index = -1) {
        fseek(pFile, 0, SEEK_END);
    } else {
        fseek(pFile, _class_size * index, SEEK_SET);
    }
   result = fwrite(reg, _class_size, cantidad, pFile);
   fclose(pFile);
   return result > 0;
}
