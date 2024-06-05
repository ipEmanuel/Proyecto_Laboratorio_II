#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string.h>

//#include <AuthManager.h>
//#include <User.h>

using namespace std;

class MenuItem {
    public:
        MenuItem(string title, string decorator = "");
        string getTitleToShow();
        void setDecorator(string decorator);
        void setCode(int code);
        int getCode();
        virtual int execute();

    protected:

    private:
        string _title;
        string _decorator;
        int _code;
};

#endif // MENUITEM_H
