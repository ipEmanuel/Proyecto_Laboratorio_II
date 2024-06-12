#ifndef ROLESMANAGER_H
#define ROLESMANAGER_H

#include <string>
#include <MenuItem.h>

using namespace std;

class RolesManager: public MenuItem {
    public:
        RolesManager(int defaultRole = -1);
        void askForRole();
        bool hasRoleSet();
        bool roleIsValid(int otherRole);
        int execute();

    protected:

    private:
        int _roleOperador;
        int _roleManager;
        string _roleOperadorDescription;
        string _roleManagerDescription;
        int _currentRole;
};

#endif // ROLESMANAGER_H
