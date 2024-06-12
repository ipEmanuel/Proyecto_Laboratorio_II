#include "RolesManager.h"

#include <iostream>
#include <MenuItem.h>

using namespace std;

RolesManager::RolesManager(int defaultRole): MenuItem("Cambiar rol", -1) {
    _currentRole = defaultRole;
    _roleOperador = 1;
    _roleManager = 2;
    _roleOperadorDescription = "OPERADOR";
    _roleManagerDescription = "MANAGER";
}

void RolesManager::askForRole() {
    cout << "Por favor ingresar en que rol quiere operar" << endl;
    cout << "1: Operador (Encargado de ventas)" << endl;
    cout << "2: Manager (Encargado de stock y reposicion)" << endl;

    int role;
    cin >> role;

    while (!cin.good() && role != 1 && role != 2) {
        system("cls");
        cout << "Por favor ingresar en que rol quiere operar" << endl;
        cout << "1: Operador (Encargado de ventas)" << endl;
        cout << "2: Manager (Encargado de stock y reposicion)" << endl;
        fflush(stdin);
        cin.clear();
        cin >> role;
    }

    if (role == _roleOperador) {
        _decorator = " - ROL ACTUAL: " + _roleOperadorDescription;
    } else {
        _decorator = " - ROL ACTUAL: " + _roleManagerDescription;
    }

    _currentRole = role;
    system("cls");
}

bool RolesManager::hasRoleSet() {
    return _currentRole != -1;
}

bool RolesManager::roleIsValid(int otherRole) {
    return otherRole == -1 || _currentRole == otherRole;
}

int RolesManager::execute(){
    system("cls");
    this->askForRole();
    return 0;
}
