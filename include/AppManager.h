#pragma once
#include "MenuItem.h"
#include "AutoparteManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "MarcaManager.h"
#include "ProveedorManager.h"

class AppManager: public MenuItem {
    public:
        void menu();
        AppManager();
        //~AppManager();
    private:
        AutoparteManager _am;
        ClienteManager _cm;
        EmpleadoManager _em;
        MarcaManager _mm;
        ProveedorManager _pm;
};
