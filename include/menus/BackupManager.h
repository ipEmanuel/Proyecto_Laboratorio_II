#pragma ONCE

#include "MenuItem.h"
#include "string"

class BackupManager: public MenuItem {
    public:
        BackupManager();
        int execute();

    protected:

    private:
        void crearBackups();
        void reestablecerBackups();
        void mostrarResultado(string archivo, bool result);
};
