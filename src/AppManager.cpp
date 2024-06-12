#include "AppManager.h"
#include <iostream>
using namespace std;

AppManager::AppManager(): MenuItem("Ventas") {}

void AppManager::menu(){
    int option;
    /*
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AUTOPARTES " << endl;
        cout << "2- CLIENTES" << endl;
        cout << "3- EMPLEADOS" << endl;
        cout << "4- MARCAS" << endl;
        cout << "5- PROVEEDOR" << endl;
        cout << "6- REPORTES" << endl;
        cout << "7- CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option){
        case 1:
            _am.menu();
            system("pause");
            break;

        case 2:
            _cm.menu();
            system("pause");
            break;
        case 3:
            _em.menu();
            system("pause");
            break;

        case 4:
            _mm.menu();
            system("pause");
            break;

        case 5:
            _pm.menu();
            system("pause");
            break;
        }
    }while(option != 0);
    */
}
