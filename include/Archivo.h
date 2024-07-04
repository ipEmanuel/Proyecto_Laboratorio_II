#pragma once
#include "string"

using namespace std;

class Archivo
{
    public:
        Archivo();
        Archivo(string nombre_archivo, size_t classSize, bool default_backup_mode = false);

    protected:
        const char* obtenerNombreArchivo();
        void setBackupMode(bool active);
        bool crearBackup(int cantReg, const void* data);
        bool sobreescribirTodo(int cantReg, const void* data);
        int getCantidadRegistros();
        bool leer(int index, void* puntero, int cantidad = 1);
        bool guardar(const void* reg, int cantidad = 1, int index = -1);

    private:
        string _archivo_nombre = string("");
        bool _backup_mode;
        size_t _class_size;
        char aux[25];
};

