#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class MenuItem {
    public:
        MenuItem();
        MenuItem(string title, int role = -1, string decorator = "");
        string getTitleToShow();
        void setDecorator(string decorator);
        void setCode(int code);
        int getCode();
        int getRole();
        virtual int execute();

    protected:
        string _decorator;

    private:
        string _title;
        int _code;
        int _role;
};
