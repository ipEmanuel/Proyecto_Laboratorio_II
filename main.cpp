#include <iostream>

#include "Menu.h"
#include "AppManager.h"
#include "AutoparteManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "MarcaManager.h"
#include "ProveedorManager.h"
#include "FacturaManager.h"
#include "BackupManager.h"
#include "Exit.h"

int main() {

    Menu menu;

    menu.setHeader("-----------------------------\n------ MENU PRINCIPAL ------- \n-----------------------------");

    AutoparteManager autoparteManager;
    ClienteManager clienteManager;
    EmpleadoManager empleadoManager;
    MarcaManager marcaManager;
    ProveedorManager proveedorManager;
    FacturaManager facturaManager;
    BackupManager backupManager;
    Exit exit;

    menu.addMenuItem(&autoparteManager);
    menu.addMenuItem(&clienteManager);
    menu.addMenuItem(&empleadoManager);
    menu.addMenuItem(&marcaManager);
    menu.addMenuItem(&proveedorManager);
    menu.addMenuItem(&facturaManager);
    menu.addMenuItem(&backupManager);
    menu.addMenuItem(&exit);

    menu.createMenuLoop();
    //AppManager app;
    //app.menu();
    return 0;
}
