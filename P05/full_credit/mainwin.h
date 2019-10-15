#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();

    private:
        Store *_store;
        Gtk::Label* label;
    

    protected:
        void on_quit_click();


    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};
#endif 

