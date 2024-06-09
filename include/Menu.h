#pragma once
#include <MenuItem.h>
using namespace std;

class Menu{
    private:
        MenuItem **_options;
        int _optionsQuantity;
        int _currentOptions = 0;
        string _header;
        int executeOption(int option);
        void printHeader();
    public:
        Menu();
        virtual ~Menu();
        void printMenu();
        int waitForOption();
        bool checkIfOptionIsValid(int option);
        void createMenuLoop(bool oneTime = false);
        void addMenuItem(MenuItem menuItem[]);
        void setHeader(string header);

};
