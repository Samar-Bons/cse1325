#include "mainwin.h"
#include <iostream>
 

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store)
 :  _store{&store},
    data{Gtk::manage(new Gtk::Label{"This is the text area. Will update later."})}
    

 

 
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
    menubar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);


    Gtk::MenuItem *menuitem_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add_sweet", true));
    menuitem_add_sweet->signal_activate().connect([this]{this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add_sweet);

    Gtk::MenuItem *menuitem_list_sweets = Gtk::manage(new Gtk::MenuItem("_List_sweets", true));
    menuitem_list_sweets->signal_activate().connect([this]{this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list_sweets);

    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About..", true));
    menuitem_about->signal_activate().connect([this]{this->on_about_click();});
    helpmenu->append(*menuitem_about);



    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);

    Gtk::MenuItem *menuitem_place = Gtk::manage(new Gtk::MenuItem("_Place", true));
    menuitem_place->signal_activate().connect([this]{this->on_place_order_click();});
    ordermenu->append(*menuitem_place);

    Gtk::MenuItem *menuitem_list = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list->signal_activate().connect([this]{this->on_list_orders_click();});
    ordermenu->append(*menuitem_list);





 

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

    vbox->show_all();

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click(){
    close();
}

void Mainwin::on_new_store_click(){

    _store = &Store();


}

void Mainwin::on_add_sweet_click(){

EntryDialog ed{*this, "Add a sweet and its price."};
ed.set_text("Sweet name","Sweet Price");
//ed.set_text2("Sweet Price");

ed.run();

Sweet swit = Sweet(ed.get_text1(),(double)ed.get_text2());

_store->add(swit);


}

void on_list_sweets_click(){
    std::string temp = "";
    for (int i = 0; i < _store->num_sweets(); i++){
        temp = temp + (_store->sweet(i+1)).name() + std::to_string((_store->sweet(i+1)).price())+"/n";
    }
    label->set_text(temp);
}

void on_about_click(){

    MessageDialog md{*this, "Mav's Ultimate Sweet Shop. /n Ver 1.0.0 /n Samarjit Singh Bons /n LGPL v2.1"};

    md.run();


}

void on_place_order_click(){
    EntryDialog ed1{*this, "Add a sweet number and quantity."};
    ed1.set_text("Sweet number","Sweet Quantity");
    ed1.run();

    Order oda;

    oda->add(_store->(sweet((int)ed1.get_text1())),ed1.get_text2());



}

void on_list_orders_click(){
    EntryDialog ed2{*this, "Please enter order number."};
    ed2.set_text("Order number","");
    ed2.run();

    std::cout<<(_store->order((int)ed2.get_text1()));
    
}



// /////////////////
// U T I L I T I E S
// /////////////////


