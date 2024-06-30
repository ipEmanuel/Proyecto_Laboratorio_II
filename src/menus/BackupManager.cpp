#include "BackupManager.h"
#include "AutoparteArchivo.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "FacturaArchivo.h"
#include "Detalle_FArchivo.h"

using namespace std;

BackupManager::BackupManager() : MenuItem("Copia de seguridad")
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

void BackupManager::reestablecerBackups()
{
    AutoparteArchivo autoparteArchivo;
    ClienteArchivo clienteArchivo;
    EmpleadoArchivo empleadoArchivo;
    FacturaArchivo facturaArchivo;
    Detalle_FArchivo detalleFacturaArchivo;

    autoparteArchivo.reestablecer();
    clienteArchivo.reestablecer();
    empleadoArchivo.reestablecer();
    facturaArchivo.reestablecer();
    detalleFacturaArchivo.reestablecer();

    cout << "REESTABLECIMIENTO COMPLETO...";
}

int BackupManager::execute()
{

    int option = -1;

    while (option != 0)
    {
        system("cls");
        cout << "Tener en cuenta que para reestablecer debe haber por lo menos un archivo de cada .dat en formato .bkp. Los puedes generar todos realizando un backup completo" << endl;
        cout << "1 - Realizar backup completo" << endl;
        cout << "2 - Reestablecer desde backup" << endl;
        cout << "0 - Volver" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            crearBackups();
            break;
        case 2:
            reestablecerBackups();
            break;
        }

        system("pause");
    }

    return 0;
}
