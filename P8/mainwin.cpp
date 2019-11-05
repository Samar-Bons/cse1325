#include "mainwin.h"
//#include <cmath>

Mainwin::Mainwin() 
: data{Gtk::manage(new Gtk::Label{"Data: "})},
  msg{Gtk::manage(new Gtk::Label{"Message: "})},
  shelter{"new_shelter"}
 {
    set_title("Mav's Animal Shelter Software ");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    
    //MENU BAR //
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    // // // F I L E / // / 

     Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //      --   Q U I T --   //
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->set_tooltip_markup("Exit the program.");
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);




     //     A N I M A L  /// ///
    // Create a animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    // -- New Animal -- //
    Gtk::MenuItem *menuitem_new_animal = Gtk::manage(new Gtk::MenuItem("_New_Animal", true));
    menuitem_new_animal->set_tooltip_markup("Add new Animal. ");
    menuitem_new_animal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_new_animal);

    // -- List Animals -- //
    Gtk::MenuItem *menuitem_list_animals = Gtk::manage(new Gtk::MenuItem("_List_Animals", true));
    menuitem_list_animals->set_tooltip_markup("List Animals. ");
    menuitem_list_animals->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_list_animals);

    //T O O L   B A R //

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   ANIMAL 
    // Add a new animal icon
    Gtk::ToolButton *new_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_animal_button->set_tooltip_markup("Animal -> New ");
    new_animal_button->signal_clicked().connect([this] {this->on_new_animal_click();});
    toolbar->append(*new_animal_button);


    //     List Animals 
    // Add a list animals icon
    Gtk::ToolButton *list_animals_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    list_animals_button->set_tooltip_markup("Animal -> List");
    list_animals_button->signal_clicked().connect([this] {this->on_list_animals_click();});
    toolbar->append(*list_animals_button);


    //     Q U I T
    // Add a quit icon
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("File -> Quit");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);





    vbox->show_all();


  
}

Mainwin::~Mainwin() { }

void Mainwin::on_quit_click(){
  
    hide();

}

void Mainwin::on_new_animal_click(){

    EntryDialog ed{*this,"Attributes for new dog."};
    ed.set_text1("Breed...");
    ed.set_text2("Name..");
    ed.set_text3("Gender (M/F)");
    ed.set_text4("Age");

    ed.run();

    std::string = breed;
    breed = ed.get_text1();
    Dog_breed db;
    if((breed.compare("retriever"))==0)
    db = retriever;

    if((breed.compare("pug"))==0)
    db = pug;

    if((breed.compare("frenchie"))==0)
    db = frenchie;

    if((breed.compare("english"))==0)
    db = english;


    if((breed.compare("mastiff"))==0)
    db = mastiff;


    if((breed.compare("pitbull"))==0)
    db = pitbull;



    if((breed.compare("shepherd"))==0)
    db = shepherd;

    if((breed.compare("collie"))==0)
    db = collie;



    

    std::string name = ed.get_text2();

    std::string gender = ed.get_text3();

    Gender gndr;

    if((gender.compare("M"))==0)
    gndr = M;

    if((gender.compare("F"))==0)
    gndr = F;

    int age = std::stoi(ed.get_text4());

    Dog doge{db,name,gndr,age};

    shelter->add_animal(doge);
        
    
}

void Mainwin::on_list_animals_click(){

int j = shelter->num_animals();

int i;
std::string dat = "";

for(i = 0; i < j; i++){
    dat = dat + (shelter.animal(i)).to_string()+"/n";
}
    data->set_text(dat);
}




EntryDialog::EntryDialog(Gtk::Window& parent,
                         const Glib::ustring& message, 
                         bool use_markup, 
                         Gtk::MessageType type, 
                         Gtk::ButtonsType buttons, 
                         bool modal)
  : MessageDialog(parent, message, use_markup, type, buttons, modal), entry1{new Gtk::Entry{}},entry2{new Gtk::Entry{}},entry3{new Gtk::Entry{}},entry4{new Gtk::Entry{}} {
    get_content_area()->pack_start(*entry1);
    get_content_area()->pack_start(*entry2);
    get_content_area()->pack_start(*entry3);
    get_content_area()->pack_start(*entry4);  // Add the entry to the MessageDialog
    entry1->show();
    entry2->show();
    entry3->show();
    entry4->show();                           // Make the Entry visible
}

// Reflect the next two methods to their equivalents in the Entry widget
void EntryDialog::set_text (const Glib::ustring& text1,const Glib::ustring& text2,const Glib::ustring& text3,const Glib::ustring& text4) {entry1->set_text(text1);entry2->set_text(text2);entry3->set_text(text3);entry4->set_text(text4);}
Glib::ustring EntryDialog::get_text1 () const {return entry1->get_text();}
Glib::ustring EntryDialog::get_text2 () const {return entry2->get_text();}
Glib::ustring EntryDialog::get_text3 () const {return entry3->get_text();}
Glib::ustring EntryDialog::get_text4 () const {return entry4->get_text();}

