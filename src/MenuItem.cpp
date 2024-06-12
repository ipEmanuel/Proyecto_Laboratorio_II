#include "MenuItem.h"

MenuItem::MenuItem() {
    _code = 0;
    _title = string("");
    _decorator = string("");
}

MenuItem::MenuItem(string title, int role, string decorator) {
    _code = 0;
    _title = title;
    _role = role;
    _decorator = decorator;
}

string MenuItem::getTitleToShow() {
    return to_string(_code) + ": " + _title + _decorator;
}

int MenuItem::getRole() {
    return _role;
}

void MenuItem::setDecorator(string decorator) {
    _decorator = decorator;
}

void MenuItem::setCode(int code) {
    _code = code;
}

int MenuItem::getCode() {
    return _code;
}

int MenuItem::execute() {
    cout << "Not implemented";
    system("pause");
    return 0;
}
