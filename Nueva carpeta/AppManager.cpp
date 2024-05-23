#include <iostream>
#include "AppManager.h"

using namespace std;

void AppManager::menu()
{
    int option;
    do
    {
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "-----------------------------" << endl;
        cout << "1- AUTOPARTES " << endl;
        cout << "2- CLIENTES" << endl;
        cout << "3- REPORTES" << endl;
        cout << "4- CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            _am.menu();
            system("pause");
            break;

        case 2:
            _cm.menu();
            system("pause");
            break;
        }

    }
    while(option != 0);

}
