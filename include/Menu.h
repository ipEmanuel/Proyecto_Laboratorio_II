#ifndef MENU_H
#define MENU_H

#include <MenuItem.h>
#include <RolesManager.h>

using namespace std;

class Menu
{
    public:
        Menu(int defaultRole = -1);
        virtual ~Menu();
        void printMenu();
        int waitForOption();
        bool checkIfOptionIsValid(int option);
        void createMenuLoop(bool oneTime = false);
        void addMenuItem(MenuItem *menuItem);
        void setHeader(string header);

    protected:

    private:
        MenuItem **_options;
        int _optionsQuantity;
        int _currentOptions = 0;
        string _header;
        int executeOption(int option);
        void printHeader();
        void askForRole();
        RolesManager _roleManager;
};

#endif // MENU_H
