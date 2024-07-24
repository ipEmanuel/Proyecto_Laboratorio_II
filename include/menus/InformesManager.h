#pragma once
#include "MenuItem.h"

class InformesManager : public MenuItem {
public:
    InformesManager();
    int execute();
    void recaudacionPorEmpleado();
    void recaudacionPorAnio();
};
