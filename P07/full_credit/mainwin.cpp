#include "mainwin.h"
#include <cmath>

Mainwin::Mainwin() 
: scale{Gtk::manage(new Gtk::Scale)},
  frame{Gtk::manage(new Gtk::Frame{"Select an operation: "})},
  radiobutton1{Gtk::manage(new Gtk::RadioButton{"Square Root"})},
  radiobutton2{Gtk::manage(new Gtk::RadioButton{"Natural Logarithm"})},
  radiobutton3{Gtk::manage(new Gtk::RadioButton{"Trignometric Cosine"})},
  radiobutton4{Gtk::manage(new Gtk::RadioButton{"extra"})},
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
    //vbox_frame->pack_start(*radiobutton4);
    radiobutton1->join_group(*radiobutton2);
    radiobutton3->join_group(*radiobutton2);
    radiobutton4->join_group(*radiobutton2); // Put radios in the same group (unlimited permitted)
    radiobutton1->signal_clicked().connect([this] {this->on_radiobutton_click(this->on_scale_value_changed(),1);});
    radiobutton2->signal_clicked().connect([this] {this->on_radiobutton_click(this->on_scale_value_changed(),2);});
    radiobutton3->signal_clicked().connect([this] {this->on_radiobutton_click(this->on_scale_value_changed(),3);});
    radiobutton4->set_active();

    vbox->pack_start(*progressbar);
    progressbar->set_show_text(true);
    progressbar->set_text("Here's the result:");
    progressbar->set_fraction(0.0);

    vbox->show_all();


  
}

Mainwin::~Mainwin() { }

int Mainwin::on_scale_value_changed() {
    int sp = scale->get_value();
    //label->set_text(std::to_string(sp*sp));
    //progressbar->set_fraction(sqrt(scale->get_value())/10.0);
    return sp;
}

void Mainwin::on_radiobutton_click(int sp,int button) {
    //Gtk::MessageDialog{*this, "Radio Button " + std::to_string(button)}.run();
    double result;
    if(button == 1){
        result = sqrt(sp);
        progressbar->set_fraction(result/100);
        progressbar->set_text(std::to_string(result));
        progressbar->set_show_text(true);

    }
    else if(button == 2){
        result = log(sp);
        progressbar->set_fraction(result/100);
        progressbar->set_text(std::to_string(result));
        progressbar->set_show_text(true);

    }
    else if(button == 3){
        result = (cos(sp));
        progressbar->set_fraction(result);
        progressbar->set_text(std::to_string(result));
        progressbar->set_show_text(true);

    }
}







