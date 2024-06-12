#include "AutoparteArchivo.h"

bool AutoparteArchivo::guardar(Autoparte reg){
   bool result;
   FILE *pFile;
   pFile = fopen("autopartes.dat", "ab");
   if(pFile == nullptr){
      return false;
   }
   result = fwrite(&reg, sizeof (Autoparte), 1, pFile);
   fclose(pFile);
   return result;
}

bool AutoparteArchivo::guardar(int index, Autoparte reg){
   bool result;
   FILE *pFile;
   pFile = fopen("autopartes.dat", "rb+");
   if(pFile == nullptr){
      return false;
   }
   fseek(pFile, sizeof(Autoparte) * index, SEEK_SET);
   result = fwrite(&reg, sizeof (Autoparte), 1, pFile);
   fclose(pFile);
   return result;
}

int AutoparteArchivo::buscarByID(int id){
    Autoparte reg;
    int pos = 0;
    FILE * pFile;
    pFile = fopen("autopartes.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Autoparte), 1, pFile)){
        if(reg.getIDAutoparte() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Autoparte AutoparteArchivo::leer(int index){
   bool result;
   Autoparte reg;
   FILE *pFile;
   pFile = fopen("autopartes.dat", "rb");
   if(pFile == nullptr){
      return reg;
   }
   fseek(pFile, index * sizeof (Autoparte), SEEK_SET);
   fread(&reg, sizeof(Autoparte), 1, pFile);
   fclose(pFile);
   return reg;
}

void AutoparteArchivo::leerTodos(Autoparte registros[], int cantidad){
   bool result;
   FILE *pFile;
   pFile = fopen("autopartes.dat", "rb");
   if(pFile == nullptr){
      return;
   }
   fread(registros, sizeof(Autoparte), cantidad, pFile);
   fclose(pFile);
}

int AutoparteArchivo::getCantidadRegistros(){
   FILE *pFile;
   int tam;
   pFile = fopen("autopartes.dat", "rb");
   if(pFile == nullptr){
      return 0;
   }
   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Autoparte);
   fclose(pFile);
   return tam;
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
