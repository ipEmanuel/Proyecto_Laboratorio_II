#include "Menu.h"

Menu::Menu(int defaultRole) {
    _optionsQuantity = 5;
    _options = new MenuItem*[_optionsQuantity];
    _header = string("");
    _roleManager = RolesManager(defaultRole);
    this->addMenuItem(&_roleManager);
}

Menu::~Menu() {
    delete[] _options;
}

void Menu::setHeader(string header) {
    _header = header;
}

void Menu::printMenu() {
    printHeader();
    for (int i = 0; i < _currentOptions; i++) {
        if (_roleManager.roleIsValid(_options[i]->getRole())) {
            cout << _options[i]->getTitleToShow() << endl;
        }
    }
    return;
}

void Menu::addMenuItem(MenuItem *menuItem) {
    if (_currentOptions == _optionsQuantity) {
        MenuItem** _newOptions = new MenuItem*[_optionsQuantity * 2];
        for (int i = 0; i < _currentOptions; i++) {
            _newOptions[i] = _options[i];
        }
        delete[] _options;
        _options = _newOptions;
        _optionsQuantity = _optionsQuantity * 2;
    }
    menuItem->setCode(_currentOptions);
    _options[_currentOptions] = menuItem;
    _currentOptions++;
}

int Menu::waitForOption() {

    int option;

    fflush(stdin);

    cin >> option;

    while (!checkIfOptionIsValid(option)) {
        cout << "Por favor ingresar una opcion valida:" << endl;
        fflush(stdin);
        cin.clear();
        cin >> option;
    }
    return option;
}

bool Menu::checkIfOptionIsValid(int option) {
    bool isValid = false;

    if (cin.good()) {
        for (int i  = 0; i < _currentOptions && !isValid; i++) {
            if (
                _roleManager.roleIsValid(_options[i]->getRole()) &&
                _options[i]->getCode() == option
                ) {
                return true;
            }
        }
    }
    return isValid;
}

int Menu::executeOption(int option) {
    for (int i=0; i < _currentOptions; i++) {
        if (_options[i]->getCode() == option) {
            system("cls");
            printHeader();
            MenuItem* po = _options[i];
            return po->execute();
        }
    }
}

void Menu::createMenuLoop(bool oneTime) {

    if (!_roleManager.hasRoleSet()) {
        _roleManager.askForRole();
    }

    this->printMenu();
    int option = this->waitForOption();
    int shouldContinue = this->executeOption(option);
    system("cls");
    while(!oneTime && shouldContinue == 0) {
        this->printMenu();
        int option = this->waitForOption();
        shouldContinue = this->executeOption(option);
        system("cls");
    }
}

void Menu::printHeader() {
    if (!_header.empty()) {
        cout << _header << endl;
    }
}
