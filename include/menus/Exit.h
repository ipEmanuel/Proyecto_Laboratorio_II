#ifndef EXIT_H
#define EXIT_H

#include "MenuItem.h"

class Exit : public MenuItem {
    public:
        Exit();
        virtual int execute();

    protected:

    private:
};

#endif // EXIT_H
