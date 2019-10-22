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
        Gtk::Label* data;
    

    protected:
        void on_quit_click();
        void on_new_store_click();
        void on_add_sweet_click();
        void on_list_sweets_click();
        void on_about_click();
        void on_place_order_click();
        void on_list_orders_click();






    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};

    // custom EntryDialog for entering sweets name and price.

class EntryDialog : public Gtk::MessageDialog{
    public:
    EntryDialog(Gtk::Window& parent,
    const Glib::ustring& message,
    bool use_markup=false,
    Gtk::MessageType type=Gtk::MESSAGE_OTHER,
    Gtk::ButtonsType buttons=Gtk::BUTTONS_OK,
    bool modal=false)

    : MessageDialog(parent,message,use_markup,type,buttons,modal), 
      entry1{new Gtk::Entry{}},
      entry2{new Gtk::Entry{}}
      {
        get_content_area()->pack_start(*entry1);
        get_content_area()->pack_start(*entry2);

        entry1->show();
        entry2->show();
    }

    void set_text(const Glib::ustring& text1,const Glib::ustring& text2){
        entry1->set_text(text1);
        entry2->set_text(text2);

    }

    Glib::ustring get_text1 () const{
        return entry1->get_text();

    }

    Glib::ustring get_text2 () const{
        return entry2->get_text();

    }

    private:
    Gtk::Entry* entry1;
    Gtk::Entry* entry2;
};

#endif 

