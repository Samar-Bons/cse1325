#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    //void on_button_click();
    void on_scale_value_changed();
    void on_radiobutton_click(int button);
  private:
    //Gtk::Button* button;
    Gtk::Scale* scale;
    Gtk::Frame* frame; // Contains the 3 radio buttons
    Gtk::RadioButton* radiobutton1;
    Gtk::RadioButton* radiobutton2;
    Gtk::RadioButton* radiobutton3; 
    Gtk::ProgressBar* progressbar;
};
