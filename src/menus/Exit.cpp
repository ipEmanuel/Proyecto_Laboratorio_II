#include "Exit.h"
#include "MenuItem.h"

Exit::Exit(): MenuItem("Salir") {
}

int Exit::execute() {
    //cout << "Gracias por usar nuestro programa c:" << endl;
    return 1;
}
