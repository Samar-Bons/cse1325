#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store)
 :  _store{&store},
    label{Gtk::manage(new Gtk::Label{"This is the text area. Will update later."})},
    

 

 
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



// /////////////////
// U T I L I T I E S
// /////////////////


