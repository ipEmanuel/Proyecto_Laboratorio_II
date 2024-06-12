#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string.h>

//#include <AuthManager.h>
//#include <User.h>

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

    private:
        string _title;
        string _decorator;
        int _code;
        int _role;
};

#endif // MENUITEM_H
