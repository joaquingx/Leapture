#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include "examplewindow.h"
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  virtual ~HelloWorld();
  ExampleWindow* examplewindow;

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Box m_VBox;
  Gtk::Button m_button;
  Gtk::Entry m_entry;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H