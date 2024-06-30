#pragma ONCE

#include "MenuItem.h"

class BackupManager: public MenuItem {
    public:
        BackupManager();
        int execute();

    protected:

    private:
        void crearBackups();
        void reestablecerBackups();
};
