#pragma once
#include "AutoparteManager.h"
#include "ClienteManager.h"

class AppManager{
public:
    void menu();
private:
    AutoparteManager _am;
    ClienteManager _cm;
};
