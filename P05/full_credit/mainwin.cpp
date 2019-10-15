#include "mainwin.h"
#include <iostream>
 

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store)
 :  _store{&store},
    data{Gtk::manage(new Gtk::Label{"This is the text area. Will update later."})},
    

 

 
  {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_title("MUSS.");
    

    // Set up a vertical box to hold the main window elements
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); 

    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar,Gtk::PACK_SHRINK,0);

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this]{this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New_Store", true));
    menuitem_new_store->signal_activate().connect([this]{this->on_new_store_click();});
    filemenu->append(*menuitem_new_store);





    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    menubar->append(*menuitem_sweets;
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);


    Gtk::MenuItem *menuitem_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add_sweet", true));
    menuitem_add_sweet->signal_activate().connect([this]{this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add_sweet);

    Gtk::MenuItem *menuitem_list_sweets = Gtk::manage(new Gtk::MenuItem("_List_sweets", true));
    menuitem_list_sweets->signal_activate().connect([this]{this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list_sweets);

 

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



     // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click(){
    close();
}

void Mainwin::on_new_store_click(){

    _store = Store();


}

void Mainwin::on_add_sweet_click(){

EntryDialog ed{*this, "Add a sweet and its price."};
ed.set_text1("Sweet name");
ed.set_text2("Sweet Price");

ed.run();

Sweet swit = Sweet(ed.get_text1(),(double)ed.get_text2());

_store->add(swit);


}



// /////////////////
// U T I L I T I E S
// /////////////////


