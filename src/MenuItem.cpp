#include "MenuItem.h"

MenuItem::MenuItem(string title, string decorator) {
    _code = 0;
    _title = title;
    _decorator = decorator;
}

string MenuItem::getTitleToShow() {
    return to_string(_code) + ": " + _title + _decorator;
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
    return 0;
}
