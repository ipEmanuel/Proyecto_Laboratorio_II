#include <iostream>

#include "Menu.h"
#include "AppManager.h"
#include "AutoparteManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "MarcaManager.h"
#include "ProveedorManager.h"
#include "Exit.h"

int main()
{
    Menu menu;

    menu.setHeader("-----------------------------\n------ MENU PRINCIPAL ------- \n-----------------------------");

    //menu.addMenuItem(new AppManager());
    menu.addMenuItem(new AutoparteManager());
    menu.addMenuItem(new ClienteManager());
    menu.addMenuItem(new EmpleadoManager());
    menu.addMenuItem(new MarcaManager());
    menu.addMenuItem(new ProveedorManager());
    menu.addMenuItem(new Exit());

    menu.createMenuLoop();
    //AppManager app;
    //app.menu();
    return 0;
}
