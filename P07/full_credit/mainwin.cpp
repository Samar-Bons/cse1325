#include "mainwin.h"

Mainwin::Mainwin() 
: scale{Gtk::manage(new Gtk::Scale)},
  frame{Gtk::manage(new Gtk::Frame{"Select an operation: "})},
  radiobutton1{Gtk::manage(new Gtk::RadioButton{"Radio Button 1"})},
  radiobutton2{Gtk::manage(new Gtk::RadioButton{"Radio Button 2"})},
  radiobutton3{Gtk::manage(new Gtk::RadioButton{"Radio Button 3"})},
  progressbar{Gtk::manage(new Gtk::ProgressBar)}

 {
    set_title("Samarjit Singh Bons 2");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // to Mainwin

    vbox->pack_start(*scale);
    scale->set_range(0.0, 100.0);
    scale->set_increments(1.0, 1.0);
    scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});

    vbox->pack_start(*frame);  // Frames can include only one widget, so we need another VBox
    Gtk::VBox *vbox_frame = Gtk::manage(new Gtk::VBox);
    frame->add(*vbox_frame);

    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1RadioButton.html
    // https://developer.gnome.org/gtkmm-tutorial/stable/sec-radio-buttons.html.en
    vbox_frame->pack_start(*radiobutton1); // Note: Added to the *frame* above
    vbox_frame->pack_start(*radiobutton2);
    vbox_frame->pack_start(*radiobutton3);
    radiobutton1->join_group(*radiobutton2);
    radiobutton2->join_group(*radiobutton3); // Put radios in the same group (unlimited permitted)
    radiobutton1->signal_clicked().connect([this] {this->on_radiobutton_click(1);});
    radiobutton2->signal_clicked().connect([this] {this->on_radiobutton_click(2);});
    radiobutton3->signal_clicked().connect([this] {this->on_radiobutton_click(3);});

    vbox->pack_start(*progressbar);
    progressbar->set_show_text(true);
    progressbar->set_text("Adjust ProgressBar (below) with Scale (above)");
    progressbar->set_fraction(0.0);

    vbox->show_all();


  
}

Mainwin::~Mainwin() { }

void Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    //label->set_text(std::to_string(sp*sp));
    progressbar->set_fraction(sqrt(scale->get_value())/10.0);


