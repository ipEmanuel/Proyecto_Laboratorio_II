#pragma once
#include <MenuItem.h>
<<<<<<< HEAD
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

=======
using namespace std;

class Menu{
>>>>>>> 2e9ccd0c06ae47e068321c061817273f2baf1763
    private:
        MenuItem **_options;
        int _optionsQuantity;
        int _currentOptions = 0;
        string _header;
        int executeOption(int option);
        void printHeader();
<<<<<<< HEAD
        void askForRole();
        RolesManager _roleManager;
};
=======
    public:
        Menu();
        virtual ~Menu();
        void printMenu();
        int waitForOption();
        bool checkIfOptionIsValid(int option);
        void createMenuLoop(bool oneTime = false);
        void addMenuItem(MenuItem menuItem[]);
        void setHeader(string header);
>>>>>>> 2e9ccd0c06ae47e068321c061817273f2baf1763

};
