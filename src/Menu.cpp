#include "Menu.h"

Menu::Menu() {
    _optionsQuantity = 10;
    _options = new MenuItem*[_optionsQuantity];
    _header = string("");
}

Menu::~Menu() {
    for (int i=0; i < _currentOptions; i++) {
        delete _options[i];
    }
    delete _options;
}

void Menu::setHeader(string header) {
    _header = header;
}

void Menu::printMenu() {
    printHeader();
    for (int i = 0; i < _currentOptions; i++) {
        cout << _options[i]->getTitleToShow() << endl;
    }
    return;
}

void Menu::addMenuItem(MenuItem menuItem[]) {
    _options[_currentOptions] = menuItem;
    menuItem->setCode(_currentOptions);
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
            isValid = _options[i]->getCode() == option;
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
    this->printMenu();
    int option = this->waitForOption();
    int shouldContinue = this->executeOption(option);

    while(!oneTime && shouldContinue == 0) {
        this->printMenu();
        int option = this->waitForOption();
        shouldContinue = this->executeOption(option);
    }
}

void Menu::printHeader() {
    if (!_header.empty()) {
        cout << _header << endl;
    }
}
