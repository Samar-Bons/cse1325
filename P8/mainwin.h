#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_quit_click();
    void on_new_animal_click();
    void on_list_animals_click();
    void on_new_client_click();
    void on_list_clients_click();
    void on_adopt_animals_click();
    void on_list_adopted_click(); 
    void status(std::string s);
  private:
    Gtk::Label* data;
    Gtk::Label* msg;
    Shelter* shelter;
};

class EntryDialog : public Gtk::MessageDialog {
  public:
                const Glib::ustring& message, 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false);

    void set_text (const Glib::ustring& text1,const Glib::ustring&text2,const Glib::ustring&text3,const Glib::ustring&text4);
    Glib::ustring get_text1 () const;
    Glib::ustring get_text2 () const;
    Glib::ustring get_text3 () const;
    Glib::ustring get_text4 () const;
  private:
    Gtk::Entry* entry1;
    Gtk::Entry* entry2;
    Gtk::Entry* entry3;
    Gtk::Entry* entry4;
};
#endif
