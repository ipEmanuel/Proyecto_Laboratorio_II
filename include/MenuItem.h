#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class MenuItem {
    public:
        MenuItem(string title, string decorator = "");
        string getTitleToShow();
        void setDecorator(string decorator);
        void setCode(int code);
        int getCode();
        virtual int execute();

    private:
        string _title;
        string _decorator;
        int _code;
};
