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

<<<<<<< HEAD
    protected:
        string _decorator;

=======
>>>>>>> 2e9ccd0c06ae47e068321c061817273f2baf1763
    private:
        string _title;
        int _code;
        int _role;
};
