//
// Created by joaquin on 21/09/18.
//

#ifndef LEAPGESTURES_INTER_H
#define LEAPGESTURES_INTER_H

#include <stdlib.h>     /* srand, rand */
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>

class window : public Gtk::Window
{

public:
    window();
    virtual ~window();
    void initialDisplay();
    void secondDisplay();
    //Signal handlers:
    bool cleanBox();
protected:
    void on_button_clicked();
    void on_changed(std::string);
    //Member widgets:
    Gtk::Box m_VBox;
    Gtk::Entry m_entry;
    Gtk::Button m_button;
    std::string  data;
};


#endif //LEAPGESTURES_INTER_H
