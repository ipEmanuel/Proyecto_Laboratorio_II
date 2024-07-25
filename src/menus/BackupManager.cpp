#include "BackupManager.h"
#include "AutoparteArchivo.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "FacturaArchivo.h"
#include "Detalle_FArchivo.h"

using namespace std;

BackupManager::BackupManager() : MenuItem("Copia de seguridad", 2)
{
}

void BackupManager::crearBackups()
{
    AutoparteArchivo autoparteArchivo;
    ClienteArchivo clienteArchivo;
    EmpleadoArchivo empleadoArchivo;
    FacturaArchivo facturaArchivo;
    Detalle_FArchivo detalleFacturaArchivo;

    autoparteArchivo.crearBackup();
    clienteArchivo.crearBackup();
    empleadoArchivo.createBackup();
    facturaArchivo.crearBackup();
    detalleFacturaArchivo.createBackup();

    cout << "BACKUP COMPLETO...";
}

void BackupManager::mostrarResultado(string archivo, bool result) {

    if (result) {
        cout << archivo << " fue reestablecido con exito" << endl;
    } else {
        cout << "Ocurrio un error al reestablecer " << archivo << endl;
    }

}

void BackupManager::reestablecerBackups()
{
    AutoparteArchivo autoparteArchivo;
    ClienteArchivo clienteArchivo;
    EmpleadoArchivo empleadoArchivo;
    FacturaArchivo facturaArchivo;
    Detalle_FArchivo detalleFacturaArchivo;

    bool result;

    mostrarResultado("autopartes", autoparteArchivo.reestablecer());
    mostrarResultado("clientes", clienteArchivo.reestablecer());
    mostrarResultado("empleados", empleadoArchivo.reestablecer());
    mostrarResultado("facturas", facturaArchivo.reestablecer());
    mostrarResultado("detalles de facturas", detalleFacturaArchivo.reestablecer());

    cout << "REESTABLECIMIENTO COMPLETO...";
}

int BackupManager::execute()
{

    int option = -1;

    while (cin.fail() || option != 0)
    {
        cin.clear();
        fflush(stdin);
        system("cls");
        cout << "Tener en cuenta que para reestablecer debe haber por lo menos un archivo de cada .dat en formato .bkp. Los puedes generar todos realizando un backup completo" << endl;
        cout << "1 - Realizar backup completo" << endl;
        cout << "2 - Reestablecer desde backup" << endl;
        cout << "0 - Volver" << endl;

        cout << "OPCION: ";

        cin >> option;

        switch (option)
        {
        case 1:
            crearBackups();
            break;
        case 2:
            reestablecerBackups();
            break;
        case 0:
            break;
        default:
            cout << "Por favor ingresar una opcion valida" << endl;
            break;
        }
        system("pause");
    }

    return 0;
}
